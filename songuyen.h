void nhapso(int a[100],int n){
	for(int i=0;i<n;i++)
	{
		printf("so nguyen thu %d :",i);
		scanf("%d",&a[i]);
	}
}
void xuatso(int a[100],int n){
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
int phepcong(int a[],int n){
	int s=0;
	for (int i=0;i<n;i++)
	{
		s=a[i]+s;
	}
	return s;
}
int pheptru(int a[],int n){
	int s=0;
	for (int i=0;i<n;i++)
	{
		s=a[i]-s;
	}
	return s;
}
int phepnhan(int a[],int n){
	int s=1;
	for (int i=0;i<n;i++)
	{
		s=a[i]*s;
	}
	return s;
}


