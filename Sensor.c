#include <stdio.h>
#include <stdlib.h>
struct sensor
{
    int id;
    float temperature;
    float pressure;
    int timest;
    
};
const int safepressuremin=950;
const int safepressuremax=1050;
const int safetempmin=0;
const int safetempmax=50;

struct sensor* insert(int*size,int*capacity,struct sensor *sp)
{
    
    if(*size==*capacity)
    {
        *capacity=*capacity*2;
        sp=(struct sensor*)realloc(sp,sizeof(struct sensor)*(*capacity));
    }
    printf("enter id temp pressure time:");
    scanf("%d %f %f %d",&sp[*size].id,&sp[*size].temperature,&sp[*size].pressure,&sp[*size].timest);
    (*size)++;
    return sp;
    
}
void saferange(int*size,struct sensor*sp)
{
    for(int i=0;i<*size;i++)
    {
        if(sp[i].pressure<safepressuremin||sp[i].pressure>safepressuremax||sp[i].temperature<safetempmin||
        sp[i].temperature>safetempmax)
        {
            printf("%d\t%f\t%f\t%d\t",sp[i].id,sp[i].temperature,sp[i].pressure,sp[i].timest);
        }
    }
}

void avgpress(struct sensor*sp,int*size)
{
    int count=0,sid;
    float total=0;
    printf("enter sensor id for avg press:");
    scanf("%d",&sid);
    for(int i=0;i<*size;i++)
    {
        if(sp[i].id==sid)
        {
            total+=sp[i].pressure;
            count++;
            
        }
    }
    if(count==0)
    {
        printf("not found");
    }
    else
    {
        printf("avg pressure %f",total/count);
    }
}
 void display(struct sensor*sp,int *size)
int main()
{
    int size=0,capacity=3,a;
    struct sensor* sp=(struct sensor*)malloc(sizeof(struct sensor)*capacity);
    while(1)
    {
        scanf("%d",&a);
        switch(a)
        {
            case 1:
            sp=insert(&size,&capacity,sp);
            break;
            
            case 2:
            saferange(&size,sp);
            break;
            
            case 3:
            avgpress(sp,&size);
        }
    }
    
}
