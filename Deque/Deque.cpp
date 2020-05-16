
#include <iostream>
using namespace std;
template<class type>
struct QueneNode
{
	type data;
	QueneNode<type>* next, * prev;
	QueneNode() { next = NULL; prev = NULL; }
	QueneNode(const type& item, QueneNode<type>* point_1 = NULL, QueneNode<type>* point_2 = NULL) //����һ���ǿս�� 
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
	void clear();//�������
	bool push_back(type& value);//�ڶ�β����һ��
	bool push_front(type& value);//�ڶ�������һ��
	bool pop_back();//�ڶ�βɾ��һ��
	inline unsigned size() { return qsize; }
	type Find(unsigned i); //����[]���ص�i�����λ�õ�����data 
protected:
	unsigned qsize;  //�� 
	QueneNode<type>* head, * tail; //ͷָ�룬βָ��    
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
	add_tail = new QueneNode<type>;   //����һ���½��
	if (add_tail == NULL)   //���䲻�ɹ�
	{
		printf("push back add_tail is false!!!");
		exit(1);
	}

	add_tail->data = value;           //��value�����½�� 
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
		//add_tail->next = tail;            //����������� 
		//add_tail->prev = tail->prev;
		//tail->prev = add_tail;            //����������� 
	}

	qsize++;
	return true;
}


template<class type>
bool Deque<type>::push_front(type& value)
{
	QueneNode<type>* add_head;
	add_head = new QueneNode<type>;   //����һ���½��
	if (add_head == NULL)   //���䲻�ɹ�
	{
		printf("push front add_tail is false!!!");
		exit(1);
	}
	add_head->data = value;           //��value�����½��
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
		//add_head->prev = head;            //�����������
		//add_head->next = head->next;
		//head->next = add_head;            //����������� 
	}

	qsize++;
	return true;
}


template<class type>
bool Deque<type>::pop_back()
{
	if (qsize == 0)            //����Ϊ�� 
		return false;
	else
	{
		QueneNode<type>* will_delete;
		will_delete = tail;         //������β���
		if (qsize > 1) {
			//tail->prev->next = NULL;
			tail = tail->prev;
			tail->next = NULL;
		}

		delete will_delete;             //�����β���
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
	printf("�����ɹ�\n");
	printf("����%d\n", a.size());
	//printf("%d\n", *a.tail);
	//QueneNode<int>* p;
	//p = a.tail;
	int i = 0;
	for (i = 1; i <= a.size(); i++) {
		cout << "1." << i << ": " << a.Find(i) << endl;
	}
	a.pop_back();
	printf("����%d\n", a.size());
	for (i = a.size(); i > 0; i--) {
		cout << "2." << i << ": " << a.Find(i) << endl;
	}

}
*/