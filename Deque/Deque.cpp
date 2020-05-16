
#include <iostream>
using namespace std;
template<class type>
struct QueneNode
{
	type data;
	QueneNode<type>* next, * prev;
	QueneNode() { next = NULL; prev = NULL; }
	QueneNode(const type& item, QueneNode<type>* point_1 = NULL, QueneNode<type>* point_2 = NULL) //构造一个非空结点 
	{
		data = item; next = point_1; prev = point_2;
	}
};

template<class type>
class Deque
{
public:
	//Deque();
	~Deque();
	void clear();//清除队列
	bool push_back(type& value);//在队尾增加一个
	bool push_front(type& value);//在队首增加一个
	bool pop_back();//在队尾删除一个
	inline unsigned size() { return qsize; }
	type Find(unsigned i); //重载[]返回第i个结点位置的数据data 
protected:
	unsigned qsize;  //表长 
	QueneNode<type>* head, * tail; //头指针，尾指针    
};


template<class type>
type Deque<type>::Find(unsigned i)
{
	if (i > qsize || i <= 0)
		exit(1);
	else
	{
		QueneNode<type>* p = head;
		for (unsigned j = 1; j < i; j++)
			p = p->next;
		return p->data;
	}
}

/*
template<class type>
Deque<type>::Deque()
{

	qsize=0;
}
*/
template<class type>
Deque<type>::~Deque()
{
	clear();
}

template<class type>
void Deque<type>::clear()
{
	while (pop_back());
}


template<class type>
bool Deque<type>::push_back(type& value)
{
	QueneNode<type>* add_tail;
	add_tail = new QueneNode<type>;   //建立一个新结点
	if (add_tail == NULL)   //分配不成功
	{
		printf("push back add_tail is false!!!");
		exit(1);
	}

	add_tail->data = value;           //将value赋给新结点 
	if (qsize == 0) {
		head = add_tail;
		tail = add_tail;
		//head->next = add_tail;
		head->prev = NULL;
		tail->next = NULL;
		//tail->prev = add_tail;
	}
	else {
		add_tail->prev = tail;
		add_tail->next = NULL;
		tail->next = add_tail;
		tail = add_tail;
		//tail->prev->next = add_tail;
		//add_tail->next = tail;            //正向链接完毕 
		//add_tail->prev = tail->prev;
		//tail->prev = add_tail;            //反向链接完毕 
	}

	qsize++;
	return true;
}


template<class type>
bool Deque<type>::push_front(type& value)
{
	QueneNode<type>* add_head;
	add_head = new QueneNode<type>;   //建立一个新结点
	if (add_head == NULL)   //分配不成功
	{
		printf("push front add_tail is false!!!");
		exit(1);
	}
	add_head->data = value;           //将value赋给新结点
	if (qsize == 0) {
		head = add_head;
		tail = add_head;
		head->prev = NULL;
		tail->next = NULL;
		head->next = add_head;
		tail->prev = add_head;
	}
	else {
		add_head->prev = NULL;
		add_head->next = head;
		head->prev = add_head;
		head = add_head;

		//head->next->prev = add_head;
		//add_head->prev = head;            //反向链接完毕
		//add_head->next = head->next;
		//head->next = add_head;            //正向链接完毕 
	}

	qsize++;
	return true;
}


template<class type>
bool Deque<type>::pop_back()
{
	if (qsize == 0)            //链表为空 
		return false;
	else
	{
		QueneNode<type>* will_delete;
		will_delete = tail;         //锁定队尾结点
		if (qsize > 1) {
			//tail->prev->next = NULL;
			tail = tail->prev;
			tail->next = NULL;
		}

		delete will_delete;             //清除队尾结点
		qsize--;
		return true;
	}
}



//#endif /* Deque_hpp */
/*int main() {
	printf("Let's begin!!!\n");
	Deque<int> a;
	int num0 = 404;
	int num1 = 212;
	a.push_back(num0);
	a.push_back(num1);
	a.push_back(num1);
	a.push_back(num0);
	printf("建立成功\n");
	printf("表长：%d\n", a.size());
	//printf("%d\n", *a.tail);
	//QueneNode<int>* p;
	//p = a.tail;
	int i = 0;
	for (i = 1; i <= a.size(); i++) {
		cout << "1." << i << ": " << a.Find(i) << endl;
	}
	a.pop_back();
	printf("表长：%d\n", a.size());
	for (i = a.size(); i > 0; i--) {
		cout << "2." << i << ": " << a.Find(i) << endl;
	}

}
*/