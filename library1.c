void vprint (int v,int l);
void vprint (float v,int l);
void vprint (double v,int l);


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
