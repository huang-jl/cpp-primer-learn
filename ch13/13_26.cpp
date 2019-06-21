#include<memory>
#include<string>
#include<vector>

using namespace std;

class BlobStr
{
	//�������ݺ�֮ǰһ��
public:
	BlobStr(const BlobStr&bs):sp(make_shared<vector<string>>(*bs.sp)) {};
	BlobStr&operator =(const BlobStr&rhs);
private:
	shared_ptr<vector<string>>sp;
};

BlobStr& BlobStr::operator =(const BlobStr&rhs)
{
	sp = make_shared<vector<string>>(*rhs.sp);
	return *this;
}