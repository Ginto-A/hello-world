//������������������λ���ֵĺͣ���λ���ֵ�ƽ���ͣ�����������
//�� 100~10000 �ڵ����г��������������ǵ�ƽ������
#include <stdio.h>


int isPrime(int x);
int splitNum(int x, int num[]);

int main()
{
    int a = 100;
    int count = 0;

    for(a = 100; a < 10000; a++){
		int i = 0, sum = 0, product = 0;
	    int num[5] = {0};
		for(i = 0; i < splitNum(a, num); i++){
			sum += num[i];
			product += num[i] * num [i];
		}
		if(isPrime(a) && isPrime(sum) && isPrime(product)){
			count++;
			printf("%d\t", a);
			if(count % 5 == 0) printf("\n");
		}			
	}
	
	return 0;
}

int isPrime(int x){
    int i = 2;
	if(x < 2) return 0;
	for(i = 2; i < x; i++){
    	if(x % i == 0){
    		return 0;
		}
	}
	return 1;
}
int splitNum(int x, int num[]){
	int i = 0;
	for(i = 0; x >= 10; i++){
		num[i] = x % 10;
		x = x / 10;
	}//λ�ǵ���� 
	num[i] = x;
	return i + 1;
}
