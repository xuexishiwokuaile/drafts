bool ListDelete(SqList*&L,int i,ElemType &e)
{
    int j;
    if(i<1||i>L->length)
        return false;
    i--;   //物理序号
    e=L->data[i];
    for(j=i;j<l->length;j++)
        L->data[j]=L->data[j+1];   //前移
    L->length--;
    return true;
}

bool ListInsert(SqList *&L,int i,ElemType e)
{
    int j;
    if(i<1||i>L->length+1)
        return false;
    i--;
    for(j=L->length;j>i;j--)
        L->data[j]=L->data[j-1];  //后移
    // for(j=i+1;j<L->length;j++)
    //     L->data[j]=L->data[j-1];
    L->data[i]=e;
    L->length++;
    return true;
}

void delnode1(SqList *&A,ElemType x)
{
    int k=0,i;
    for(i=0;i<A->length;i++)  //扫描
    {
        if(A->data[i]!=x)
        {
            A->data[k]->A->data[i];  //重利用A的空间
            k++;
        }
    }
    A->length=k;
}

void delnode2(SqList *&A,ElemType x)
{
    int k=0,i=0;  //k为元素x的个数
    while(i<A->length)  //扫描
    {
        if(A->data[i]==x)
            k++;
        else
            A->data[i-k]=A->data[i]; //前移k个位置
        i++;
    }
    A->length-=k;
}

void move1(SqList *&L)
{
    int i=0,j=L->length-1;
    int tmp;
    int pivot = L->data[0];  //以data[0]为基准
    while(i<j)
    {
        while(i<j&&L->data[j]>pivot)
            j--;  //从后向前扫描，找一个<=pivot的元素
        while(i<j&&L->data[i]<=pivot)
            i++;  //从前向后扫描，找一个>pivot的元素
        if(i<j)
        {
            //交换
            tmp = L->data[i];  
            L->data[i]=L->data[j];
            L->data[j]=tmp;    
        }
    }
    //交换(此时i=j)
    tmp=L->data[0];
    L->data[0]=L->data[j];
    L->data[j]=tmp;
}

void move2(SqList *&L)
{
    int i=0,j=L->length-1;
    int pivot = L->data[0];
    while(i<j)
    {
        while(j>i&&L->data[j]>pivot)
            j--;
        L->data[i]=L->data[j];
        while(i<j&&L->data[i]<=pivot)
            i++;
        L->data[j]=L->data[i];
    }
    L->data[i]=pivot;
}

void createListF(LinkNode *&L,ElemType a[],int n)  //头插法
{
    LinkNode *s;
    int i;
    L=(LinkNode *)malloc(sizeof(LinkNode));  //头结点
    L->next=NULL;
    for(int i=0;i<n;i++)
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=a[i];
        s->next=L->next;
        L->next=s;
    }
}

void createListR(LinkNode *&L,ElemType a[],int n)  //尾插法
{
    LinkNode *s,*r;
    int i;
    L=(LinkNode *)malloc(sizeof(LinkNode));  //创建头结点
    r=L;  //r始终指向尾结点，开始时指向头结点
    for(i=0;i<n;i++)
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=a[i];
        r->next=s;  //插入到r之后
        r=s;
    }
    r->next=NULL;
}

bool ListInsert(LinkNode *&L,int i,ElemType e)
{
    int j=0;
    LinkNode *p=L;
    LinkNode *s;
    while(j<i-1&&p!=NULL)
    {
        p=p->next;
        j++;
    }
    if(p==NULL)
        return false;
    else
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return true;
    }
}

void delmaxnode(LinkNode *&L)  //删除最大值结点
{
    LinkNode *p=L->next,*pre=L,*maxp=p,*maxpre=pre;
    while(p!=NULL)
    {
        if(maxp->data<p->data)
        {
            maxp=p;
            maxpre=pre;
        }
        pre=p;
        p=p->next;
    }
    maxpre->next=maxp->next;
    free(maxp);
}

void sort(LinkNode *&L)  //递增有序表
{
    LinkNode *p,*pre,*q;
    p=L->next->next;  //第2个数据结点
    L->next->next=NULL;
    while(p!=NULL)
    {
        q=p->next;  //保存p的后继指针

        pre=L;
        while(pre->next!=NULL&&pre->next->data<p->data)
            pre=pre->next;
        
        p->next=pre->next;
        pre->next=p;
        p=q;
    }
}

void LinkTable(HList *h1,HList *h2,Hlist *&H)
{
    int i,j,k;
    DList *p=h1->next,*q,*s,*r;

    h=(HList *)malloc(sizeof(HList));
    h->next=NULL;
    h->Row=0;
    h->Col=h1->Col+h2->Col;
    while(p!=NULL)
    {
        q=h2->next;
        while(q!=NULL)
        {
            if(p->data[i-1]==q->data[j-1])
            {
                s=(DList *)malloc(sizeof(DList));
                for(k=0;k<h1->Col;k++)  //复制表1的当前行
                    s->data[k]=p->data[k];
                for(l=k=0;k<h2->Col;k++)  //复制表2的当前行
                    s->data[h1->Col+k]=q->data[k];
                if(h->next==NULL)
                    h->next=s;
                else
                    r->next=s;
                r=s;
                h->Row++;
            }
            q=q->next;
        }
        p=p->next;
    }
    r->next=NULL;
}

//顺序表存放有序表时的二路归并算法
void UnionList(SqList *LA,SqList *LB,SqList *&LC)
{
    int i=0,j=0,k=0;
    LC=(SqList *)malloc(sizeof(SqList));
    while(i<LA->length&&j<LB->length)
    {
        if(LA->data[i]<LB->data[i])
        {
            LC->data[k]=LA->data[i];
            i++;k++;
        }
        else
        {
            LC->data[k]=LB->data[j];
            j++;k++;
        }
    }
    while(j<LA->length)  //LA尚未扫描完，将其余元素插入LC中
    {
        LC->data[k]=LA->data[i];
        i++;k++;
    }
    while(j<LB->length)  //LB尚未扫描完，将其余元素插入LC中
    {
        LC->data[k]=LB->data[j];
        j++;k++;
    }
    LC->length=k;
}

//单链表存放有序表时的二路归并算法
void UnionList1(LinkNode *LA,LinkNode *LB,LinkNode *&LC)
{
    LinkNode *pa=LA->next,*pb=LB->next,*r,*s;
    LC=(LinkNode *)malloc(sizeof(LinkNode));
    r=LC;  //r始终指向LC的尾结点
    while(pa!=NULL&&pb!=NULL)
    {
        if(pa->data<pb->data)
        {
            s=(LinkNode *)malloc(sizeof(LinkNode));
            s->data=pa->data;
            r->next=s;r=s;  //尾插法
            pa=pa->next;
        }
        else
        {
            s=(LinkNode *)malloc(sizeof(LinkNode));
            s->data=pb->data;
            r->next=s;r=s;
            pb=pb->next;
        }
    }
    while(pa!=NULL)  //没有扫描完
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=pa->data;
        r->next=s;r=s;
        pa=pa->next;
    }
    while(pb!=NULL)
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=pb->data;
        r->next=s;r=s;
        pb=pb->next;
    }
    r->next=NULL;
}

