#include<stdio.h>

/*Considere�a�fun��o�seguinte,�codificada�na�linguagem�de�programa��o�C�(o operador % significa resto da divis�o inteira):*/
void surpresa (int n) {
	int a=0, b=0;
	while (n>0)
	{
		if ((n%2)==0)
			a=a+1;
		else
			b=b+1;
		n=n/2;
	}
	printf ("%d %d\n", a, b);
}

main() {
	
	surpresa (2);//n=2.
	
}

/*Os dois valores impressos pela fun��o s�o iguais quando o valor de n �:*/

