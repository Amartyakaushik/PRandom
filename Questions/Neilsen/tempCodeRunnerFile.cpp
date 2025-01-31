(int[] arr, int n, int 1)

{

PriorityQueue<Integer> p = new PriorityQueue<>();

int ct = 0

int res = 1;

for (int i = 0 ; i < n ; i++)

p.add(arr[i]);

for(;p.isEmpty() == false && ct < 1 ct++)

{

res = res * p.element();

p.remove();

}

return res;
}