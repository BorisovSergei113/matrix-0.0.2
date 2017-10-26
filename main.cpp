#include <iostream>
#include <sstream>
using namespace std;

float **mat1_p;
float **mat2_p;
float **mat3_p;

void create_mat (int stroki,int stolbi,int num_mat) {
    if(num_mat==1){
        mat1_p=new float* [stroki];
        
        for(int i =0; i<stroki ;i++){
            mat1_p[i]=new float [stolbi];
        }
    }
    if(num_mat==2){
        mat2_p=new float* [stroki];
        
        for(int i =0; i<stroki ;i++){
            mat2_p[i]=new float [stolbi];
        }
    }
}

void enter_mat(int stroki,int stolbi,int num_mat){
    if(num_mat==1){
        for (int i =0; i<stroki ; i++)
        {
            for (string string; getline(cin, string); )
            {  istringstream stream (string);
                bool failure = false;
                for (int j =0; j<stolbi; j++)
                {
                    if (!(stream>>mat1_p[i] [j]))
                    {
                        failure = true;
                        break;
                    }
                }
                if(!failure)
                    break;
                else
                {cout<<"An error has occured while reading input data"<<'\n';}
            }
        }
    }
    if(num_mat==2){
        for (int i =0; i<stroki ; i++)
        {
            for (string string; getline(cin, string); )
            {  istringstream stream (string);
                bool failure = false;
                for (int j =0; j<stolbi; j++)
                {
                    if (!(stream>>mat2_p[i] [j]))
                    {
                        failure = true;
                        break;
                    }
                }
                if(!failure)
                    break;
                else
                {cout<<"An error has occured while reading input data"<<'\n';}
            }
        }
    }
}


void delete_mem(int stroki)
{
    
    for (int i=0; i<stroki; i++) {
        delete [] mat1_p[i];
    }
    delete [] mat1_p;
    
    for (int i=0; i<stroki; i++) {
        delete [] mat2_p[i];
    }
    delete [] mat2_p;
    
    for (int i=0; i<stroki; i++) {
        delete [] mat3_p[i];
    }
    delete [] mat3_p;
}

void plus_mat(int stroki,int stolbi,int stroki2,int stolbi2){
    if(stroki==stroki2 && stolbi==stolbi2)
    {
        mat3_p=new float* [stroki];
        for(int i =0; i<stroki ;i++)
        {
            mat3_p[i]=new float [stolbi];
        }
        for (int i = 0; i<stroki; i++)
        {
            for( int j = 0; j<stolbi; j++)
            {
                int res;
                res=mat1_p[i][j]+mat2_p[i][j];
                mat3_p[i] [j] = res;
            }
        }
    }
    else{cout<<"An error has occured while reading input data"<<endl;
        exit(0);
    }
}


void minus_mat(int stroki,int stolbi,int stroki2,int stolbi2){
    if(stroki==stroki2 && stolbi==stolbi2)
    {
        mat3_p=new float* [stroki];
        for(int i =0; i<stroki ;i++)
        {
            mat3_p[i]=new float [stolbi];
        }
        for (int i = 0; i<stroki; i++)
        {
            for( int j = 0; j<stolbi; j++)
            {
                int res;
                res=mat1_p[i][j]-mat2_p[i][j];
                mat3_p[i] [j] = res;
            }
        }
    }
    else{cout<<"An error has occured while reading input data"<<endl;
        exit(0);
    }
}

void umnog_mat(int stroki,int stolbi,int stroki2,int stolbi2){
    if(stolbi==stroki2)
    {
        mat3_p=new float* [stroki];
        for(int i =0; i<stroki ;i++)
        {
            mat3_p[i]=new float [stolbi2];
        }
        
        for(int i = 0; i < stroki; i++)
            for(int j = 0; j < stolbi2; j++)
            {
                mat3_p[i][j] = 0;
                for(int k = 0; k < stroki2; k++)
                    mat3_p[i][j] += mat1_p[i][k] * mat2_p[k][j];
            }
    }
    else{cout<<"An error has occured while reading input data"<<endl;
        exit(0);
    }
}

void transp_mat(int stroki,int stolbi){
    mat3_p=new float* [stolbi];
    for(int i =0; i<stolbi ;i++){
        mat3_p[i]=new float [stroki];
    }
    
    
    for(int i = 0; i<stolbi; i++){
        for(int j = 0; j<stroki; j++){
            mat3_p[i][j] = mat1_p[j][i];
        }
    }
}


void out_mat(int stroki,int stolbi,int trans)
{  if(trans==false){
    cout<<endl;
    for (int i=0; i<stroki; i++)
    {
        for (int j =0 ; j<stolbi; j++)
        {
            cout<<mat3_p[i][j]<<" ";
        }
        cout<<'\n';
    }
    exit(0);
}
    
else{
    cout<<endl;
    for (int i=0; i<stolbi; i++)
    {
        for (int j =0 ; j<stroki; j++)
        {
            cout<<mat3_p[i][j]<<" ";
        }
        cout<<'\n';
    }
    exit(0);
}
}

void Short_Mat(float **mat1_p,float **p,int i,int j,int stroki ){
    int ki, kj, di, dj;
    di = 0;
    for (ki = 0; ki<stroki - 1; ki++) {
        if (ki == i) di = 1;
        dj = 0;
        for (kj = 0; kj<stroki - 1; kj++) {
            if (kj == j) dj = 1;
            p[ki][kj] = mat1_p[ki + di][kj + dj];
        }
    }
}

int opredel(float **mat1_p,int stroki){
    int i,d,k,n,j;
    
    float **p;
    p=new float*[stroki];
    for(int i=0;i<stroki;i++){
        p[i]=new float[stroki];
    }
    j=0;
    d=0;
    k=1;
    n=stroki-1;
    if (stroki<1) {cout << "An error has occured while reading input data"; exit(0);}
    if (stroki == 1) {
        d = mat1_p[0][0];
        return(d);
    }
    if (stroki == 2) {
        d = mat1_p[0][0] * mat1_p[1][1] - (mat1_p[1][0] * mat1_p[0][1]);
        return(d);
    }
    if (stroki>2) {
        for (i = 0; i<stroki; i++) {
            Short_Mat(mat1_p, p, i, 0, stroki);
            d = d + k * mat1_p[i][0] * opredel(p, n);
            k = -k;
        }
    }
    for (int i=0; i<stroki; i++) {
        delete [] p[i];
    }
    delete [] p;
    return(d);
}



void obrat_mat(int stroki,int stolbi,float a){
    if(stroki==stolbi && a!=0){
        
        float **M;
        M=new float*[stroki];
        for (int i=0; i<stroki; i++) {
            M[i]=new float[stroki];
        }
        float **V;
        V=new float*[stroki];
        for (int i=0; i<stroki; i++) {
            V[i]=new float[stroki];
        }
        int x=0;
        for(int i=0;i<stroki;i++){
            for (int j=0; j<stroki; j++) {
                Short_Mat(mat1_p,V,i,j,stroki);
                float m =opredel(V,stroki-1);
                x=i+j;
                if((x%2)!=0) m=m*(-1);
                M[i][j]=m;
            }
        }
        
        for(int i=0;i<stroki;i++){
            for (int j=0; j<stroki; j++) {
                M[i][j] *= (1/a);
            }
        }
        
        
        for(int i = 0; i<stolbi; i++){
            for(int j = 0; j<stroki; j++){
                cout<<M[j][i]<<" ";
            }
            cout<<endl;
        }
        
        for (int i=0; i<stroki; i++) {
            delete [] M[i];
        }
        delete [] M;
        
        for (int i=0; i<stroki; i++) {
            delete [] V[i];
        }
        delete [] V;
        
        exit(0);
    }
    else{cout<<"An error has occured while reading input data"<<endl;}
}

int main() {
    int stroki = 0,stolbi=0,stroki2=0,stolbi2=0;
    char op= ' ';
    
    scanf("%d%*c%d",&stroki,&stolbi);
    cin.get();
    
    
    create_mat(stroki,stolbi,1);
    enter_mat(stroki,stolbi,1);
    
    cin>>op;
    cin.get();
    
    if(op!='T'&&op!='R'&&op!='+'&&op!='-'&&op!='*'){
        cout<<"An error has occured while reading input data"<<endl;
        exit(0);
    }
    
    switch(op){
        case 'T':
            transp_mat(stroki,stolbi);
            out_mat(stroki, stolbi, true);
            delete_mem(stroki);
            break;
            
        case 'R':
            float a=opredel( mat1_p, stroki);
            cout<<"Det="<<a<<endl;
            obrat_mat(stroki,stolbi,a);
            delete_mem(stroki);
            break;
    }
    scanf("%d%*c%d",&stroki2,&stolbi2);
    cin.get();
    
    
    create_mat(stroki2,stolbi2,2);
    enter_mat(stroki2,stolbi2,2);
    
    switch (op) {
        case '+':
            plus_mat(stroki,stolbi,stroki2,stolbi2);
            out_mat (stroki,stolbi,false);
            delete_mem(stroki);
            break;
        case '-':
            minus_mat(stroki,stolbi,stroki2,stolbi2);
            out_mat (stroki,stolbi,false);
            delete_mem(stroki);
            break;
        case '*':
            umnog_mat(stroki,stolbi,stroki2,stolbi2);
            out_mat (stroki,stolbi2,false);
            delete_mem(stroki);
            break;
            
        default:
            cout<<"An error has occured while reading input data"<<'\n';
            break;
    }
    
    
    return 0 ;
}
