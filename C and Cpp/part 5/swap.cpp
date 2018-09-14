void swap(int &x, int &y) {

	int temp;
	
	temp=x;
	x=y;
	y=temp;
}

void swap(double &x, double &y) {

	double temp;
	
	temp=x;
	x=y;
	y=temp;
}

void swap(char &x, char &y) {

	char temp;
	
	temp=x;
	x=y;
	y=temp;
}

void swap(const char *(*a), int i,int k)
{
	const char *temp;

	temp = a[i];
	a[i] = a[k];
	a[k] = temp; 
		
}

