#include"Deque.cpp"

using namespace std;

int main() {
	printf("Let's begin!!!\n");
	Deque<int> a;
	int num0 = 404;
	int num1 = 212;
	a.push_back(num0);
	a.push_back(num1);
	a.push_back(num1);
	a.push_back(num0);
	printf("±í³¤£º%d\n", a.size());
	//printf("%d\n", *a.tail);
	//QueneNode<int>* p;
	//p = a.tail;
	int i = 0;
	for (i = 1; i <= a.size();i++) {
		cout<<"1: "<<a.Find(i)<<endl;
	}
	
	
}