#pragma once
#include<set>
#include<string>

using std::set; using std::string;
class Folder;
class Message
{
	friend Folder;
	friend void swap(Message&, Message&);
public:
	explicit Message(const string&s = string()) :content(s) {}
	Message(const Message&);

	//13.49
	Message(Message&&);
	Message& operator=(Message&&);

	Message& operator =(const Message&);
	~Message();
	void save(Folder&);
	void remove(Folder&);

private:
	void addFldr(Folder&f) { folder.insert(&f); };
	void removeFldr(Folder&f) { folder.erase(&f); }
	void add_to_folder(const Message&);
	void remove_from_folder();
	//13.49
	void move_folders(Message*);
	set<Folder*>folder;
	string content;
};

class Folder
{
	friend Message;
	friend void swap(Folder&, Folder&);
public:
	Folder() = default;
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();
private:
	void addMsg(Message&);
	void remMsg(Message&);
	void add_message(const Folder&);
	void remove_message();
	set<Message*>message;
};