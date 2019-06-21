#include"13_34.h"

//Message的成员函数
Message::Message(const Message&msg)
{
	content = msg.content;
	folder = msg.folder;
	add_to_folder(msg);
}

Message& Message::operator=(const Message&msg)
{
	content = msg.content;
	remove_from_folder();
	folder = msg.folder;
	add_to_folder(msg);
	return *this;
}

Message::~Message()
{
	remove_from_folder();
}

void Message::save(Folder&f)
{
	folder.insert(&f);
	f.addMsg(*this);
}

void Message::remove(Folder&f)
{
	folder.erase(&f);
	f.remMsg(*this);
}

void Message::add_to_folder(const Message&msg)
{
	for (auto f : msg.folder)
		f->addMsg(*this);
}

void Message::remove_from_folder()
{
	for (auto f : folder)
		f->remMsg(*this);
}

void swap(Message&lhs, Message&rhs)
{
	using std::swap;
	lhs.remove_from_folder();
	rhs.remove_from_folder();
	swap(lhs.content, rhs.content);
	swap(lhs.folder, rhs.folder);
	lhs.add_to_folder(lhs);
	rhs.add_to_folder(rhs);
}
//Folder的成员函数
Folder::Folder(const Folder&f)
{
	message = f.message;
	add_message(f);
}

Folder::~Folder()
{
	remove_message();
}

Folder& Folder::operator=(const Folder&f)
{
	message = f.message;
	remove_message();
	add_message(f);
	return *this;
}

void Folder::addMsg(Message&msg)
{
	message.insert(&msg);
}

void Folder::remMsg(Message&msg)
{
	message.erase(&msg);
}

void Folder::add_message(const Folder&f)
{
	for (auto msg : f.message)
		msg->folder.insert(this);
}

void Folder::remove_message()
{
	for (auto msg : message)
		msg->folder.erase(this);
}

void swap(Folder&lhs, Folder&rhs)
{
	lhs.remove_message();
	rhs.remove_message();
	swap(lhs.message, rhs.message);
	lhs.add_message(lhs);
	rhs.add_message(rhs);
}

//13.49
void Message::move_folders(Message*m)
{
	folder = std::move(m->folder);
	for (auto f : m->folder)
	{
		f->remMsg(*m);
		f->addMsg(*this);
	}
	m->folder.clear();
}

Message::Message(Message&&rvalue_r):content(std::move(rvalue_r.content))
{
	move_folders(&rvalue_r);
}

Message& Message::operator=(Message&&rvalue_r)
{
	if (this != &rvalue_r)
	{
		remove_from_folder();
		content = std::move(rvalue_r.content);
		move_folders(&rvalue_r);
	}
	return *this;
}