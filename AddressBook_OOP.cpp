#include "UserInterface.h"
#include "MyList.h"
using namespace std;

int main(int argc, char argv[])
{
	CMyList DB;
	CUserInterface UI(DB);

	UI.Run();

	return 0;
}