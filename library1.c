/*******************************************************************************************************************/

//------->declaraction

//1 (print array)
void vprint (int v,int l);
void vprint (float v,int l);
void vprint (double v,int l);
//2 (maxinum of an array)
int max(int a[], int n);
float max(float a[], int n);
double max(double a[], int n);
//3 (minimum of an array)
int min(int a[], int n);
float min(float a[], int n);
double min(double a[], int n);
//4 (set array to zero)
void vsetzero(int a[], int n);
void vsetzero(float a[], int n);
void vsetzero(double a[], int n);
//5 (array mean)
int vmean(int a[], int n);
float vmean(float a[], int n);
double vmean(double a[], int n);




/*******************************************************************************************************************/

//------->codes

//1
void vprint(int v[], int l){ //array and long array
	for (int i=0;i<l;i++){
		printf("%d\t",v[i]);
	}
}

void vprint(float v[], int l){//array and long array
	for (int i=0;i<l;i++){
		printf("%f\t",v[i]);
	}
}

void vprint(double v[], int l){//array and long array
	for (int i=0;i<l;i++){
		printf("%f\t",v[i]);
	}
}

//2
int max(int a[], int n) {// array and array dimention
	int max=a[0];
	for (int i=0;i<n;i++)
		if (a[i]>max)
			max=a[i];
	return max;
}

float max(float a[], int n) {// array and array dimention
  float max=a[0];
	for (int i=0;i<n;i++)
		if (a[i]>max)
			max=a[i];
	return max;
}

double max(double a[], int n) {// array and array dimention
  double max=a[0];
	for (int i=0;i<n;i++)
		if (a[i]>max)
			max=a[i];
	return max;
}

//3
int min(int a[], int n) {// array and array dimention
	int max=a[0];
	for (int i=0;i<n;i++)
		if (a[i]<max)
			max=a[i];
	return max;
}

float min(float a[], int n) {// array and array dimention
  float max=a[0];
	for (int i=0;i<n;i++)
		if (a[i]<max)
			max=a[i];
	return max;
}

double min(double a[], int n) {// array and array dimention
  double max=a[0];
	for (int i=0;i<n;i++)
		if (a[i]<max)
			max=a[i];
	return max;
}


//4
void vsetzero(int a[], int n){// array and array dimention
  for(int i=0;i<n;i++)
    a[i]=0;
}

void vsetzero(float a[], int n){// array and array dimention
  for(int i=0;i<n;i++)
    a[i]=0;
}

void vsetzero(double a[], int n){// array and array dimention
  for(int i=0;i<n;i++)
    a[i]=0;
}


//5
int vmean(int v[], int n) {// array and array dimention
	int a=1;
	for (int i=0;i<n;i++)
		a+=v[i];
	return a/n;
}

float vmean(float v[], int n) {// array and array dimention
	float a=1;
	for (int i=0;i<n;i++)
		a+=v[i];
	return a/n;
}

double vmean(double v[], int n) {// array and array dimention
	double a=1;
	for (int i=0;i<n;i++)
		a+=v[i];
	return a/n;
}
