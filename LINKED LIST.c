#include<stdio.h>
#include<stdlib.h>
struct ll{
	int value;
	struct ll *address;
}*p;
struct ll *end;
void del_atend(){
	struct ll* temp=p;
	while(temp->address->address!=NULL){
		temp=temp->address;
		}
		
		struct ll *temp1=temp->address;
		temp->address=NULL;
		end=temp;
		free(temp1);
}
void del_atbeg(){
	struct ll* temp=p;
	p=p->address;
	free(temp);
}
int del_atpos(int pos){
	struct ll *temp,*temp1;
	temp=p;
	if(pos==1){
	
	del_atbeg();
	return;}
	int cou=1;
	//if(end==NULL || end->address!=NULL){
		while(cou!=pos-1){
		temp=temp->address;
		if(temp->address==NULL)
			return -1;
		cou++;
		}
		//end =temp;
		temp1=temp->address;
		temp->address=temp->address->address;
		free(temp1);
		return 0;
}
void insert_atbeg(int d){
	struct ll *temp;
	if(p==NULL){
		p=(struct ll*)malloc(sizeof(struct ll));
		//printf("jhg");
		p->value=d;
		p->address=NULL;
		end=p;
	}
	else{
		temp=(struct ll*)malloc(sizeof(struct ll));
		temp->value=d;
		temp->address=p;
		p=temp;
	}
}
void insert_atend(int d){
	struct ll *temp,*temp1;
	temp=p;
	if(end==NULL || end->address!=NULL){
		while(temp->address!=NULL){
		temp=temp->address;
		}
		end =temp;
	}
	temp1=(struct ll*)malloc(sizeof(struct ll));
		temp1->value=d;
		temp1->address=NULL;
		end->address=temp1;
}
int insert_atpos(int d,int pos){
	struct ll *temp,*temp1;
	temp=p;
	if(pos==1){
	
	insert_atbeg(d);
	return;}
	int cou=1;
	//if(end==NULL || end->address!=NULL){
		while(cou!=pos-1){
		temp=temp->address;
		if(temp==NULL)
			return -1;
		cou++;
		}
		//end =temp;
	
	temp1=(struct ll*)malloc(sizeof(struct ll));
		temp1->value=d;
		temp1->address=temp->address;
		temp->address=temp1;
		return 0;
}
void print(){
	struct ll *temp=p;
	while(temp!=NULL){
		printf("%d ",temp->value);
		temp=temp->address;
	}
	printf("\n");
}
int ele_atlast_n(int n){
	struct ll *temp,*prev;
	temp=p;
	while(n){
		temp=temp->address;
		if(temp==NULL)    //out of range pos
			return -1;
		n--;
	}
	
	prev=p;
	while(temp!=NULL){
		temp=temp->address;
		prev=prev->address;
	}
	int res=prev->value;
	return res;
}
int middle_ind(){
	struct ll* slow,*fast;
	slow=p;
	fast=p;
	while(fast!=NULL){
		fast=fast->address;
		if(fast==NULL)
		break;
		fast=fast->address;
		slow=slow->address;
	}
	return slow->value;
}
void main(){
	int ch=-1,n,res;
	while(ch!=0){
		printf("enter choice:- 1 for insert at beg \n 2 for insert at end \n 3 for insert at particular pos\n 4 to print\n 5 for delete at beg \n 6 for delete at end \n 7 for delete at particular pos\n 8 for to find nth element from last\n 9 to find middle element\n 0 for exit\n");
		int da,po;
		scanf("%d",&ch);
		switch(ch){
			case 0:break;
			case 1:printf("enter value ");
			scanf("%d",&da);
			insert_atbeg(da);
			break;
			case 2:printf("enter value ");
			scanf("%d",&da);
			insert_atend(da);
			break;
			case 3:printf("enter value ");
			scanf("%d",&da);
			printf("enter position ");
			scanf("%d",&po);
			int c=insert_atpos(da,po);
			if(c==-1)
			printf("Invalid position\n");
			break;
			case 4:print();
				break;
			case 5:del_atbeg();
			break;
			case 6:del_atend();
			break;
			case 7:
			printf("enter position ");
			scanf("%d",&po);
			int cu=del_atpos(po);
			if(cu==-1)
			printf("Invalid position\n");
			break;
			case 8:
			printf("enter n ");
			scanf("%d",&n);
			int res=ele_atlast_n(n);
			printf("%d\n",res);
			break;
			case 9:
			res=middle_ind();
			printf("%d\n",res);
			break;
			default:printf("Invalid Choice\n");
			break;
		}
		
	}
	//printf("%d",p->value);

