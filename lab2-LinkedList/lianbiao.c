/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

/*---------page 10 on textbook ---------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status; 
typedef int ElemType;

/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct Dnode{
	struct Dnode *next;
    ElemType data;
}Dnode,*LinkList;

typedef struct{  //���Ա��ļ������Ͷ���  
     struct { char name[30];  
               LinkList L;      
      } elem[10];  
      int length;  
 }LISTS; 
/*--------------------����--------------------*/
ElemType max(ElemType a,ElemType b)
{
    if(a>b) return a;
    else return b;
}
/*--------------------------------------------*/
status InitList(LinkList *L);
status DestroyList(LinkList *L);
status ClearList(LinkList *L);
status ListEmpty(LinkList L);
status ListLength(LinkList L);
status GetElem(LinkList L,int i,ElemType* e);
status LocateElem(LinkList L,ElemType e);
status PriorElem(LinkList L,ElemType e,ElemType *pre);
status NextElem(LinkList L,ElemType e,ElemType *next);
status ListInsert(LinkList *L,int i,ElemType e);
status ListDelete(LinkList *L,int i,ElemType* e);
status ListTraverse(LinkList L);
status ManyElemInsert(LinkList *L);
status ReverseList(LinkList *L);
status RemoveNthFromEnd(LinkList *L,int n);
status AddList(LISTS *Lists,char ListName[]);
status RemoveList(LISTS *Lists,char ListName[]);
status LocateList(LISTS Lists,char ListName[]);
status sortList(LinkList *L);

/*--------------------------------------------*/
void main(void){
int op=1;
/*--------------------------*/
    LinkList L;
    L=NULL;
/*--------------------------*/
    LISTS Lists;
    Lists.length=0;
/*--------------------------*/
while(op){
	system("cls");
    printf("\n\n");
	printf("      Menu for Linear Table On Sequence Structure \n");
	printf("-------------------------------------------------\n");
	printf("    	  1. InitList       7. LocateElem        13. ManyElemInsert      19. ReadFile\n");
	printf("    	  2. DestroyList    8. PriorElem         14. ReverseList         20. SaveFile\n");
	printf("    	  3. ClearList      9. NextElem          15. RemoveNthFromEnd    21. sortList\n");
	printf("    	  4. ListEmpty      10. ListInsert       16. AddList\n");
	printf("    	  5. ListLength     11. ListDelete       17. RemoveList\n");
	printf("    	  6. GetElem        12. ListTraverse     18. LocateList\n");
	printf("    	  0. Exit\n");
	printf("-------------------------------------------------\n");
	printf("    ��ѡ����Ĳ���[0~20]:");
	scanf("%d",&op);

    switch(op){
	    case 1:
		    if(InitList(&L)==OK) printf("���������ɹ���\n");
		    else printf("�����Ѵ��ڣ�\n");
		    getchar();getchar();
		    break;
	    case 2:
		    if(DestroyList(&L)==OK) printf("�������ٳɹ���\n");
		    else printf("���������ڣ�\n");    
		    getchar();getchar();
		    break;
	    case 3:
		    if(ClearList(&L)==OK) printf("���������ɹ���\n");
		    else printf("���������ڣ�\n");       
		    getchar();getchar();
		    break;
	    case 4:
		    if(ListEmpty(L)==TRUE) printf("����Ϊ�գ�\n");
		    else if(ListEmpty(L)==FALSE)printf("������Ϊ�գ�\n");     
		    else printf("���������ڣ�\n");
		    getchar();getchar();
		    break;
	    case 5:
		    if(ListLength(L)!=INFEASIBLE) printf("��������Ϊ%d��\n",ListLength(L));
            else printf("���������ڣ�\n");     
		    getchar();getchar();
		    break;
	    case 6:{
		    ElemType *e;
            int i;
            printf("������Ҫ��ȡ��λ����\n");
            scanf("%d",&i);
            if(GetElem(L,i,e)==INFEASIBLE) printf("���������ڣ�\n");
            else if(GetElem(L,i,e)==ERROR) printf("�������\n");
            else printf("��Ҫ��ȡ������Ϊ%d\n",*e);
		    getchar();getchar();
		    break;}
	    case 7:{
		    ElemType e;
            printf("��Ҫ���ҵ������ǣ�\n");
            scanf("%d",&e);
            if(LocateElem(L,e)==INFEASIBLE) printf("���������ڣ�\n");
            else if(LocateElem(L,e)==ERROR) printf("û���ҵ���\n");
            else printf("�ҵ��ˣ��ڵ�%dλ\n",LocateElem(L,e));
		    getchar();getchar();
		     break;}
	    case 8:{
		    ElemType num, *pre = &num, e;
            printf("��Ҫ���ĸ�����ǰ������");
            scanf("%d",&e);
            if(PriorElem(L,e,pre)==INFEASIBLE)  printf("���������ڣ�\n");
            else if(PriorElem(L,e,pre)==ERROR) printf("δ�ҵ���Ҫ���ҵ�����ǰ����\n");
            else printf("ǰ����Ϊ%d!\n",*pre);
		    getchar();getchar();
		    break;}
	    case 9:{
		    ElemType num,*next=num,e;
            printf("��Ҫ���ĸ����ĺ�������");
            scanf("%d",&e);
            if(NextElem(L,e,next)==INFEASIBLE)  printf("���������ڣ�\n");
            else if(NextElem(L,e,next)==ERROR) printf("δ�ҵ���Ҫ���ҵ����ĺ�����\n");
            else printf("������Ϊ%d!\n",*next);
		    getchar();getchar();
		    break;}
	    case 10:{
		    ElemType e,i,k;
            printf("��������Ҫ��������Լ�λ�ã�??",&e,&i); 
            scanf("%d %d",&e,&i);
            if((k=ListInsert(&L,i,e))==INFEASIBLE)  printf("���������ڣ�\n");
            else if(k==ERROR) printf("����λ�ò���ȷ��\n");
            else printf("����ɹ���\n");
		    getchar();getchar();
		    break;}
	    case 11:{
		    ElemType e,i,k;
            printf("��������Ҫɾ�������Լ�λ�ã�",&e,&i); 
            scanf("%d %d",&e,&i);
            if((k=ListInsert(&L,i,e))==INFEASIBLE)  printf("���������ڣ�\n");
            else if(k==ERROR) printf("ɾ��λ�ò���ȷ��\n");
            else printf("ɾ���ɹ���\n");   
		    getchar();getchar();
		    break;}
	    case 12:{
		    if(!ListTraverse(L)) printf("�����ǿձ���\n");
		    getchar();getchar();
		    break;}
        case 13:{
            if(ManyElemInsert(&L)==INFEASIBLE)  printf("���������ڣ�\n");
            else printf("������ɣ�??");
            getchar();getchar();
            break;
        }
        case 14:{
           int k;
           if((k=ReverseList(&L))==INFEASIBLE) printf("���������ڣ�\n");
           else if(k==ERROR) printf("����Ϊ��!");
           else printf("��ת��ɣ�??");
           getchar();getchar();
           break;
        }
        case 15:{
           int n,k;
           printf("������Ҫ�Ƴ��Ľڵ㵹��λ�ã�");
           scanf("%d",&n);
           if((k=RemoveNthFromEnd(&L,n))==INFEASIBLE) printf("���������ڣ�\n");
           else if(k==ERROR) printf("��������");
           else printf("���Ƴ���");
           getchar();getchar();
           break;
        }
        case 16:{
           char ListName[30];
            printf("�������¼������Ա������֣�\n");
            scanf("%s",ListName);
            if(AddList(&Lists,ListName)==ERROR) printf("����ʧ�ܣ�\n");
            else printf("����ɹ���\n");
            getchar();getchar();
           break;
        }
        case 17:{
           char ListName[30];
            printf("������Ҫɾ�����Ա������֣�\n");
            scanf("%s",ListName);
            if(RemoveList(&Lists,ListName)==ERROR) printf("ɾ��ʧ�ܣ�\n");
            else printf("ɾ���ɹ���\n");
            getchar();getchar();
           break;
        }
        case 18:{
           char ListName[30];
           int k;
            printf("������Ҫ���ҵ����Ա������֣�\n");
            scanf("%s",ListName);
            if((k=LocateList(Lists,ListName))==ERROR) printf("û���ҵ���\n");
            else printf("�ҵ��ˣ��ڵ�%d��\n",k);
            getchar();getchar();
           break;
        }
        case 19:{
            FILE* fp;
            printf("�������ļ�����\n");
            char FileName[30];
            scanf("%s", FileName);
            fp = fopen(FileName, "r+");
            if(!fp)
                printf("�ļ�δ�ҵ���\n");
            else{
                InitList(&L);
                int cnt = 0, num ;
                while (fscanf(fp, "%d", &num) != EOF)
                {
                    ListInsert(&L, ++cnt, num);
                    printf("%d\n", num);
                }
                printf("����ɶ�ȡ��\n");
            }
            fclose(fp);
            getchar();getchar();
            break;
        }
        case 20:{
            FILE *fp;
            printf("�������ļ�����\n");
            char FileName[30];
            scanf("%s", FileName);
            fp = fopen(FileName, "w+");
            if(L == NULL)
                printf("���Ա������ڣ�\n");
            else{
                LinkList p = L->next;
                while (p)
                {
                    fprintf(fp, "%d ", p->data);
                    p = p->next;
                }
                printf("д����ɣ�\n");
            }
            getchar();getchar();
           break;
        }
        case 21:{
            int k;
            if((k=sortList(&L))==INFEASIBLE) printf("���������ڣ�\n");
            else if(k==ERROR) printf("����Ϊ�գ�");
            else printf("������ɣ�??");
            getchar();getchar();
            break;
        }
	case 0:
         break;
	}//end of switch
  }//end of while
printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
}//end of main()
/*-----------------page 23 on textbook --------------------*/
status InitList(LinkList *L)
// ���Ա�L�����ڣ�����һ���յ����Ա�������OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ�����??��ɱ�������??
    /********** Begin *********/
    if((*L)!=NULL) return INFEASIBLE;
    (*L)=(LinkList) malloc(sizeof(LinkList));
    (*L)->next=NULL;
    return OK;

    /********** End **********/
}
 
status DestroyList(LinkList *L)
// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ�����??��ɱ�������??
    /********** Begin *********/
    if((*L)==NULL) return INFEASIBLE;
    // LinkList  p=(*L);
    // while (p->next)
    // {
    //     p=(*L)->next;
    //     free((*L));
    //     (*L) = p;
    // }
    // free(L);free(p);
    (*L)=NULL;
    return OK;
    /********** End **********/
}
status ClearList(LinkList *L)
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ�����??��ɱ�������??
    /********** Begin *********/
    if((*L)==NULL) return INFEASIBLE;
    LinkList p=(*L)->next,q;
    while(p->next)
    {
        q=p;
        p=q->next;
        free(q);
    }
    free(p);
    (*L)->next=NULL;
    return OK;
    /********** End **********/
}
status ListEmpty(LinkList L)
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ�����??��ɱ�������??
    /********** Begin *********/
    if(L==NULL) return INFEASIBLE;
    if(L->next==NULL) return TRUE;
    else return FALSE;

    /********** End **********/
}
int ListLength(LinkList L)
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
    // �������ﲹ�����??��ɱ�������??
    /********** Begin *********/
    if(L==NULL) return INFEASIBLE;
    LinkList p=L;
    int cnt=0;
    while(p->next)
    {
        cnt++;
        p=p->next;
    }
    return cnt;
    /********** End **********/
}
status GetElem(LinkList L,int i,ElemType *e)
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ�����??��ɱ�������??
    /********** Begin *********/
    if(L==NULL) return INFEASIBLE;
    if(i<1) return ERROR;
    int cnt=0;
    LinkList p=L;
    while(p->next)
    {
        cnt++;
        p=p->next;
    }
    if(i>cnt||i<1) return ERROR;
    cnt=0;
    p=L;
    while(p->next)
    {
        cnt++;
        p=p->next;
        if(i==cnt) 
        {
            e=p->data;
            break;
        }
    }
    return OK;
    /********** End **********/
}
status LocateElem(LinkList L,ElemType e)
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����ţ����e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
{
    // �������ﲹ�����??��ɱ�������??
    /********** Begin *********/
    if(L==NULL) return INFEASIBLE;
    LinkList p=L;
    int cnt=0;
    while(p->next)
    {
        p=p->next;
        cnt++;
        if(e==p->data)
        {
            return cnt;
        }
    }
    return ERROR;
    /********** End **********/
}
status PriorElem(LinkList L,ElemType e,ElemType *pre)
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ�����??��ɱ�������??
    /********** Begin *********/
    if(L==NULL) return INFEASIBLE;
    LinkList p=L->next,q=L;
    int num=1;
    while(q->next!=NULL && p->data!=e)
    {
        q=p;
        p=p->next;
        num++;
    }
    if(num==1) return ERROR;
    if(p==NULL) return ERROR;
    *pre=q->data;
    return OK;
    /********** End **********/
}
status NextElem(LinkList L,ElemType e,ElemType *next)
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ�����??��ɱ�������??
    /********** Begin *********/
    if(L==NULL) return INFEASIBLE;
    LinkList p=L;
    while(p->next)
    {
        p=p->next;
        if(p->data==e)
        {
            break;
        }
    }
    if(p->next==NULL) return ERROR;
    (*next)=(p->next)->data;
    return OK;
    /********** End **********/
}
status ListInsert(LinkList *L,int i,ElemType e)
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ�����??��ɱ�������??
    /********** Begin *********/
    if((*L)==NULL) return INFEASIBLE;
    LinkList p=(*L);
    int cnt=0;
    while(p->next)
    {
        p=p->next;
        cnt++;
    }
    if(i<1||i>cnt+1) return ERROR;
    p=(*L),cnt=0;
    while(p->next&&i-1>cnt)
    {
        p=p->next;
        cnt++;
    }
    LinkList r;
    r=(LinkList)malloc(sizeof(LinkList));
    r->next=p->next;
    p->next=r;
    r->data=e;
    return OK;
    /********** End **********/
}

status ListDelete(LinkList *L,int i,ElemType *e)
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ�����??��ɱ�������??
    /********** Begin *********/
    if((*L)==NULL) return INFEASIBLE;
    int cnt=0;
    LinkList p=(*L),q;
    while(p->next)
    {
        p=p->next;
        cnt++;
    }
    if(i<1||i>cnt) return ERROR;
    cnt=0;p=(*L);
    while(cnt<i-1)
    {
        p=p->next;
        cnt++;
    }
    q=p->next;
    e=q->data;
    p->next=p->next->next;
    free(q);
    return OK;
    /********** End **********/
}
status ListTraverse(LinkList L)
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ��??����OK��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ�����??��ɱ�������??
    /********** Begin *********/
    if(L==NULL) return 0;
    LinkList p=L;
    printf("-------------All Elem--------------\n");
    while(p->next)
    {
        p=p->next;
        printf("%d ",p->data);
    }
    printf("\n-------------All Elem--------------\n");
    return OK;
    /********** End **********/
}

status ManyElemInsert(LinkList *L)
{
    if((*L)==NULL) return INFEASIBLE;
    ElemType n,now;
    LinkList p=(*L);
    printf("��Ҫ����������м�����\n");
    scanf("%d",&n);
    printf("������Ҫ��������ݣ�\n");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&now);
        LinkList q=(LinkList)malloc(sizeof(LinkList));
        p->next=q;
        q->data=now;
        p=q;
    }
    p->next=NULL;
    return OK;
}

status ReverseList(LinkList *L)
{
    if((*L)==NULL) return INFEASIBLE;
    if((*L)->next==NULL) return ERROR;
    LinkList p=(*L)->next,q=(*L),r=(*L)->next->next;
    while(r)
    {
        q=p;
        p=r;
        r=p->next;
        p->next=q;
    }
    ((*L)->next)->next=NULL;
    (*L)->next=p;
    return OK;
}

status RemoveNthFromEnd(LinkList *L,int n)
{
    if((*L)==NULL) return INFEASIBLE;
    int cnt=0,num;
    LinkList p=(*L);
    while(p->next)
    {
        p=p->next;
        cnt++;
    }
    if(n<1||cnt<n) return ERROR;
    num=cnt-n+1;cnt=0; p=(*L);
    while(cnt<num-1)
    {
        p=p->next;
        cnt++;
    }
    p->next=p->next->next;
    return OK;
}
status AddList(LISTS *Lists,char ListName[])
// ֻ��Ҫ��Lists������һ������ΪListName�Ŀ����Ա������Ա������ֺ�̨���Գ������??
{
    if((*Lists).length>=10) return ERROR;
    (*Lists).elem[(*Lists).length].L=(LinkList) malloc(sizeof(LinkList));
    (*Lists).elem[(*Lists).length].L->next=NULL;
    strcpy(ListName,(*Lists).elem[(*Lists).length].name);
    (*Lists).length++;
    return OK;
}
status RemoveList(LISTS *Lists,char ListName[])
// Lists��ɾ��һ������ΪListName�����Ա�
{
    int i,j;
    if((*Lists).length==0) return ERROR;
    for(i=0;i<(*Lists).length;i++)
    {
        if(strcmp((*Lists).elem[i].name,ListName)==0)
        {
            for(j=i;j<(*Lists).length-1;j++)
            {
                (*Lists).elem[j]=(*Lists).elem[j+1];
            }
            (*Lists).length--;
            return OK;
        }
    }
    return ERROR;
}
status LocateList(LISTS Lists,char ListName[])
// ��Lists�в���һ������ΪListName�����Ա����ɹ������߼���ţ����򷵻�??0
{
    int state=0,i,j;
    for(i=0;i<Lists.length;i++)
    {
        if(strcmp(Lists.elem[i].name,ListName)==0) return i+1;
    }
    return 0;
}

status sortList(LinkList *L)
{
    if((*L)==NULL) return INFEASIBLE;
    if((*L)->next==NULL) return ERROR;
    ElemType a[101];
    LinkList p=(*L);
    int cnt=0;
    while(p->next)
    {
        p=p->next;
        cnt++;
        a[cnt]=p->data;
    }
    a[cnt]=p->data;
    for(int i=cnt;i>1;i--)
    {
        for(int j=1;j<i;j++)
        {
            if(a[j]>a[j+1])
            {
                ElemType t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        printf("%d ",a[i]);
    }
    p=(*L);cnt=0;
    while(p->next)
    {
        p=p->next;
        cnt++;
        p->data=a[cnt];
    }
    p->data=a[cnt];
    return OK;
}