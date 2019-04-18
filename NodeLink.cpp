#include <iostream>
using namespace std;

template <class A>
class list; //前置声明,定义友元时使用了

template <class A>
class list_iterator; //前置声明,定义友元时使用了

template <class A>
class node //节点
{
    friend class list<A>; //list可以访问该class的内部,友元类,也可以嵌套node(public)到list
    friend class list_iterator<A>;

public:
    node(A x)
    {
        data = x;
        next = 0; //尾巴
    }

private:
    A data;
    node *next;
};

template <class A>
class list //链表
{
    friend class list_iterator<A>;

public:
    list() { first = 0; } //空

    list(A *arr, int s, int e, bool mod = true)
    {
        first = 0;

        if (s > 0 || e > s)
            if (mod)
                for (; s <= e - 1; e--)
                    Ins(*(arr + e - 1));
            else
                for (; s <= e - 1; s++)
                    Ins(*(arr + s - 1));
        else
            std::cout << "err";
    }

    void Ins(A x)
    {
        node<A> *newnode = new node<A>(x); //新开辟节点
        newnode->next = first;             //新节点连接旧的节点
        this->first = newnode;             //新节点为头
    }

    void Dle(A x, int i = 1)
    {
        node<A> *p1 = 0, *p2; //一个用于存储上一个,一个用于循环
        int j = 0;
        for (p2 = first; p2 && p2->data != x && i != j; p1 = p2, p2 = p2->next)
            j++; //for用于遍历,找到内容所对应的指针

        if (p2)     //找到了p1(p2为true) 或 没找到p1(p2为false) 但是完成了遍历
            if (p1) //是不是头节点
                p1->next = p2->next;
            else
                this->first = first->next;
        delete p2;
    }

    void Inv()
    {
        node<A> *p1 = first, *p2 = 0; //倒数第N个和第N个交换
        for (; p1;)
        {
            node<A> *p3 = p2;
            p2 = p1; //缓存p2在p3,p2交换p1交换

            p1 = p1->next; //步长+
            p2->next = p3;
        }
        this->first = p2;
    }
    void linkNode(list<A> list_)
    {
        if (first) //本链表是不是空表
        {
            node<A> *p; //用于循环
            for (p = first; p->next; p = p->next)
                ;                  //无无其他条件遍历,用于找到尾巴
            p->next = list_.first; //和本链表尾巴连接上
        }
        else
            this->first = list_.first;
    }

    void Cout()
    {
        for (node<A> *p = first; p; p = p->next)
        {
            std::cout << p->data;
            if (p->next)
                std::cout << "->";
        }
        std::cout << std::endl;
    }

private:
    node<A> *first; //指向第一个节点的指针
};

template <class A> //迭代器
class list_iterator
{
public:
    list_iterator(const list<A> &l) : p1(l), p2(l.first){};

    bool Is_this_null() //当前迭代器指向是否为null
    {
        return p2 ? true : false;
    }

    bool Is_next_null() //当前节点的下一个节点是否为null
    {
        return p2 && p2->next ? true : false;
    }

    A *First()
    {
        return p1.first ? &p1.first->data : 0; //返回指针
    }
    const A *Next() //涉及const A与A类型转换
    {
        if (p2)
        {
            p2 = p2->next; //叠加p2
            return &p2->data;
        }
        else
            return 0;
    }
    void Cout()//迭代器打印模板
    {
        if (this->Is_this_null())
        {
            std::cout << *this->First();
            while (this->Is_next_null())
                std::cout << "->" << *this->Next();
            std::cout << std::endl;
        }
    }

private:
    const list<A> &p1;
    const node<A> *p2;
};

