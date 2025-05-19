//Pointer arithmetic is based on the size of the data type. For example, if int is 4 bytes:

int main()
{
  int arr[3] = {1, 2, 3};
  int *p = arr;
  p++; // Now points to arr[1], i.e., 4 bytes ahead
  return 0;
}
