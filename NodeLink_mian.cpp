typedef int A;
int main()
{
    A arr[] = {10, 12, 3, 455, 67};
    list<A> list1(arr, 1, 5);
    list1.Ins(10);
    list1.Cout();
    list_iterator<A> li(list1);
    li.Cout();
    system("pause");
    return 0;
}
