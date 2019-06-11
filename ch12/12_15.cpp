#include<memory>

using namespace std;

class connection {};
class destination ;
connection connect(destination*);
void disconnect(connection);

void f(destination &d)
{
	connection c = connect(&d);
	shared_ptr<connection>p(&c, [](connection*c) {disconnect(*c); });
}