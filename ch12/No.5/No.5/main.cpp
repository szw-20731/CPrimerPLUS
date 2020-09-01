#include "Customer.h"
#include "queue_.h"
#include <ctime>

using namespace std;
bool newcustomer(double x) {
	return std::rand() * x / RAND_MAX < 1;                     //����ֵλ��0��x֮�䣬 �˿�ÿx���ӵ���һ��
}
int main()
{
	int avg_wait;
	int customer_nums;
	cout << "Enter maximum size of queue: " << endl;
	cin >> customer_nums;
	queue_ line(customer_nums);
	Item customer;
	int wait_time = 0;
	int line_wait = 0;
	int nums = 0;
	int res;                                                  //ÿСʱ�������ٹ˿�
	for (res = 1; res < 10000; res++) {                        //����һ���˿���Ҫ60/res���� 
		for (int i = 0; i < 6000; i++) {                      //ģ��6000����
			if (newcustomer(60.0 / double(res)) && !line.isfull()) {  //�����¹˿��Ҷ���δ��
				customer.set(i);            
				line.enqueue(customer);
			}
			if (wait_time <= 0 && !line.isempty()) {
				line.dequeue(customer);
				wait_time = customer.get_processtime();
				line_wait += i - customer.get_arrive();
				nums++;
			}
			if (wait_time > 0)
				wait_time--;
		}
		if (line_wait / nums > 1) {
			cout << res << endl;
			break;
		}
	}
	
	system("pause");
	return 0;
}