typedef int A;
int main()
{
    A arr[] = {10, 12, 3, ,1, 2,3,455, 67};
    list<A> list1(arr, 1, 5);//初始化并且用数组初始化
    list<A> list2();//初始化空表
    list1.Ins(10);//插入(头)
    list1.Cout();//class list打印
    list1.Dle(3,2);//删除第2个3
    list1.Dle(3);//删除第1个3
    list_iterator<A> li(list1);//迭代器
    li.Cout();//迭代器打印
    system("pause");
    return 0;
}
