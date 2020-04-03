//��ҵ��������¿�ܵĴ���ϸ�ڣ������ܱ������еõ���ȷ��� 
#include <iostream>
class SuperPrime {
  public:
  	SuperPrime():number(0) {
	}
  	~SuperPrime() {
	}
  	void Setnumber(int n) {//�趨number��ֵ 
  		int *p =(int*) &number;
		*p = n;
	}
	bool isSuperPrime() {//�жϳ������� 
  	  	split(number, N);
  	  	int a = sum();//��λ���� 
	  	int b = multi();//��λ���� 
	  	int c = squareSum();//��λ��ƽ���� 
	  	if (isPrime(number) && isPrime(a) && isPrime(b) && isPrime(c))
	    	return true; 
  	  	return false;
	}
	int show() {//��ӷ���number 
		return number;
	}
  private:
  	const int number;
  	int N[5], size;//N�洢�ָ�ĸ�λ����size��ʾλ�� 
  	bool isPrime(int x) { //�ж����� 
  		int i = 2;
		if(x < 2) return false;
		for(i = 2; i < x; i++){
    		if(x % i == 0){
    			return false;
			}
		}
		return true;
	}
	void split(int number,int N[]) {
		int i = 0, x = number;
		for(i = 0; x >= 10; i++){
			N[i] = x % 10;
			x = x / 10;
		}//λ�ǵ���� 
		N[i] = x;
		size = i + 1;// number split into N
	}
	int sum() {
		int Sum = 0;
		int i;
		for(i = 0; i < size; i++)
			Sum += N[i];
		return Sum;
	}
	int multi() {
		int Multi = 1;
		int i;
		for(i = 0; i < size; i++)
			Multi *= N[i];
		return Multi;
	}
	int squareSum() {
		int square = 0;
		int i;
		for(i = 0; i < size; i++)
			square += (N[i] * N[i]);
		return square;
	}
};
class Set {
  public:
  	Set(int from, int to) {//�����жϷ�Χ 
  	  size = to - from;
  	  begin = from;
  	  end = to;
	}
  	~Set() {
	}
  	int count() { //������������ 
  	  	int count = 0;
  	  	int i;
  	  	for (i = 0; i < size; i++) {
			set[i].Setnumber(i + begin);//��ֵ 
  	    	if(set[i].isSuperPrime())//�ж� 
  	      		count += 1;
  		}
	  	return count; 
	}
  	int sum() { //���������� 
  	  	int sum = 0;
  	  	int i;
  	  	for (i = 0; i < size; i++) {
  	    	set[i].Setnumber(i + begin);//��ֵ 
			if(set[i].isSuperPrime())//�ж� 
  	      		sum += set[i].show();//number��private������ֱ�ӷ��� 
		}
  	    return sum; 
	}
  private:
  	SuperPrime set[1000];
  	int size;//�жϷ�Χ 
  	int begin, end;//��Χ��ͷ���β 
};
int main() {
  Set ss(100, 999);
  std::cout << "How Many: " << ss.count() << std::endl;
  std::cout << "Sum is " << ss.sum() << std::endl;
  return 0;
}
