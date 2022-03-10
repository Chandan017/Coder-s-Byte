Simply create a linkedlist and traverse across both the list while both are not null and carry is not equal to zero
if ll1 is not null then take it and if ll2 is not null then take it also and store first+second+ carry /10 in our answer list and store carry into carry variable .
and at the end move pointer one place next;
​
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
ListNode* ans=new ListNode(0);
ListNode* temp=ans;
int first=0,second=0,carry=0;
while(l1!=NULL ||  l2!=NULL || carry!=0)
{
if(l1!=NULL)
{
first=l1->val;
l1=l1->next;
}
else
first=0;
if(l2!=NULL)
{
second=l2->val;
l2=l2->next;
}
else
second=0;
ListNode* temp2=new ListNode(0);
temp->next=temp2;
temp=temp2;
temp->val=(first+second+carry)%10;
carry=(first+second+carry)/10;
}
ans=ans->next;
return ans;
}