//作业：大整数，比如9081321110693270343633073697474256143563558458718976746753830538032062222085722974121768604305613921745580037409259811952655310075487163797179490457039169594160088430571674960498834085812920457916453747019461644031395307920624947349951053530086146486307198155590763466429392673709525428510973272600608981219760099374675982933766845473509473676470788342281338779191792495900393751209539300628363443012 6538005862664913074813656220643842443844131905754565672075358391135537108795991638155474452610874309742867231360502542308382199053675592825240788613991898567277116881793749340807728335795394301261629479870548736450984003401594705923178314906195914825136973281314862289454100745237769034410057080703111299605127114594552921209928891515242515620324828055912854227507525717981351447473570262981491527798 
//重新设计下面的代码，使其可以处理大整数的素数与超级素数
//同时仔细理解面向对象的编程方式 
#include <iostream>
template <class A> 
class BigPrime{
public:
	BigPrime(A n) : num(n){ }
	virtual bool isPrime() const {
		int i;
		int number = num;
		for(i = 2; i < number; i++){
			if(number % i == 0) break;
		} 
		if(i != number) return false;
		return true;
	} 
private:
	const A num;
};
template <class A>
class BigSuperPrime : public BigPrime<A> {
public:
	BigSuperPrime(A n) : BigPrime<A>(n), num(n){
		int number = n;
		int t;
		int Sum = 0, Multi = 1, SquareSum = 0;
		while(number >= 10){
			t = number % 10;
			number = number / 10;
			Sum += t;
			Multi *= t;
			SquareSum += (t * t);	
		}
		Sum += number;
		Multi *= number;
		SquareSum += (number * number);
		sum = new BigPrime<A>(Sum);
		multi = new BigPrime<A>(Multi);
		squareSum = new BigPrime<A>(SquareSum);
	}
	virtual ~BigSuperPrime(){
		delete sum;
		delete multi;
		delete squareSum;
	}
	virtual bool isPrime() const {
		if(BigPrime<A>::isPrime() 
			&&sum->isPrime() 
			&& multi->isPrime() 
			&& squareSum->isPrime()) return true;
		return false;
	}
private:
	const A num;
	const BigPrime<A> *sum;
	const BigPrime<A> *multi;
	const BigPrime<A> *squareSum;
};
template <class T>
class Set{
public:
	Set(int sz);
	~Set();
	bool add(T *bp);
	bool remove(T *bp);
	int count() const {
		int ret = 0;
		for(int i = 0; i < index; i++){
			if(pset[i]->isPrime()) ret++;
		}
		return ret;
	}
	int sum() const {
		return 0;
	}
private:
	T **pset;
	int size, index;	
};

int main() {
	Set<BigPrime<double>> set(1000);
	BigSuperPrime<double> bp(2), bp1(113);
	set.add(&bp);
	set.add(&bp1);
	std::cout << set.count() << std::endl;
	return 0;
}

template <class T>
Set<T>::Set(int sz) : size(sz) {
	index = 0;
	pset = new T*[size];//分配存储空间 
}
template <class T>
Set<T>::~Set() {
	delete[] pset;//回收存储空间 
}
template <class T>
bool Set<T>::add(T *bp) {
	if(index > size) return false;
	pset[index] = bp;
	index++;//pset[index++] = bp;
	return true;
}
template <class T>
bool Set<T>::remove(T *bp){
	if(index < 0) return false;
	delete bp;
	index--;
	return true;
}
