/*Oscar BinarySearch*/

#include <iostream>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
#include <random>   // C++11 亂數庫
#include <vector>   // std::vector
#include <numeric>  // std::iota
#include <map>      //std::map
#include <unordered_map>  //std::unordered_map

#include"BinarySearch.h"
using namespace std;

DLL_API BinarySearch BinarySearchInstance;
enum LeetcodeExam {
    Leetcode704BinarySearch,

    None,
};

int main()
{
    LeetcodeExam ExamEnum = Leetcode704BinarySearch;//ChangeForExam
    vector<int> LinkedlistInput1 = { 7,13,11,10,1 };              //ChangeForExam
    vector<int> LinkedlistInput2 = { 7,13,11,10,1 };              //ChangeForExam
    int iInput1 = 0;int iInput2 = 0;
    int Ans = 0; vector<int> AnsVector; string AnsStr = "";;
    string strinput1 = "bab";
    string strinput2 = "xaabacxcabaaxcabaax";


    BinarySearch* Implementation = new BinarySearch();


    switch (ExamEnum)
    {
    case Leetcode704BinarySearch:
        Ans = Implementation->Leetcode_Sol_704(LinkedlistInput1, iInput1,1);
        break;

    default:
        break;
    }
    #pragma region BinarySearch
    BinarySearch obj1;              // 呼叫預設建構式
    obj1.display();

    BinarySearch obj2(10);          // 呼叫帶參數建構式
    obj2.display();

    obj1.setData(20);          // 修改資料成員
    obj1.display();

    return 0;
    #pragma endregion

    
}

#pragma region BinarySearch
// 預設建構式，初始化指標
BinarySearch::BinarySearch() : data(new int(0)) {
    std::cout << "Default constructor called. Data initialized to 0." << std::endl;
}

// 帶參數建構式，初始化指標並設置初始值
BinarySearch::BinarySearch(int value) : data(new int(value)) {
    std::cout << "Parameterized constructor called. Data initialized to " << value << "." << std::endl;
}

// 解構式，釋放動態分配的記憶體
BinarySearch::~BinarySearch() {
    delete data;
    std::cout << "Destructor called. Memory for data released." << std::endl;
}

// 設定資料成員
void BinarySearch::setData(int value) {
    *data = value;
}

// 取得資料成員
int BinarySearch::getData() const {
    return *data;
}

// 顯示資料
void BinarySearch::display() const {
    std::cout << "Data: " << *data << std::endl;
}
#pragma endregion



#pragma region 考題一:基礎二分搜尋

#pragma region 技巧
/*
        1.一律都用小中值(left + right >> 1)，除非特殊題(已經限制了)
        2.判斷找的值是不是確定在vector裡面：
          vector不一定有要找的值:
          迴圈判斷式：while(left<=right)
          right = middle - 1 和 left = middle + 1 (大部分，用下面nums[mid]的判斷，要用哪一個)
          vector一定有要找的值:
          迴圈判斷式：while(left < right)
          right = middle  (大部分，用下面nums[mid]的判斷，要用哪一個)

          left = mid + 1 幾乎是一致的，但 right 需要根據題目調整

          if(nums[mid] > target)(這個能知道要不要留middle)：
          right = mid - 1 和 right = mid 的選擇，取決於 mid 是否還可能是答案：
          如果 mid 確定不是答案，應該完全排除 (right = mid - 1)
          如果 mid 可能是答案，不能直接排除 (right = mid)

        3.確定寫的東西一定有收斂

        4.大多題目都是return left：因為：middle = (小中值)
        原因：int middle = (right + left) >> 1;的關係，所以right有機會跳過答案
        在偶數對情況下：middle = 左側最大值(簡稱：小中值)，所以left不會跳過(因為條件判斷式：都是用num[mid]判斷
        在奇數對情況下：奇數對不談，因為對稱

        Leetcode 704. Binary Search 跟 Find Minimum in Rotated Sorted Array (Leetcode 153)配著看!
        */
#pragma endregion

#pragma region Leetcode 704. Binary Search
//Leetcode 704. Binary Search
int BinarySearch::Leetcode_Sol_704(std::vector<int>& nums, int target, int _solution) {
    switch (_solution)
    {
    case 1:
        return BinarySearch_704(nums, target);
    default:
        return -1; // 確保所有路徑都有回傳值
    }

    return-1;
}

int BinarySearch::BinarySearch_704(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + right >> 1;
        if (nums[mid] > target) right = mid - 1;
        else if (nums[mid] < target) left = mid + 1;
        else return mid;
    }

    return -1;
}
#pragma endregion

#pragma region Leetcode 35. Search Insert Position
//Leetcode 35. Search Insert Position
int BinarySearch::Leetcode_Sol_35(std::vector<int>& nums, int target, int _solution) {
    switch (_solution)
    {
    case 1:
        return BinarySearch_35(nums, target);
    default:
        return -1; // 確保所有路徑都有回傳值
    }

    return-1;
}

int BinarySearch::BinarySearch_35(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + right >> 1;
        if (nums[mid] > target) right = mid - 1;
        else if (nums[mid] < target) left = mid + 1;
        else return mid;
    }
    return left;

}
#pragma endregion

#pragma region Leetcode 33. Search in Rotated Sorted Array
//Leetcode 33. Search in Rotated Sorted Array
int BinarySearch::Leetcode_Sol_33(std::vector<int>& nums, int target, int _solution) {
    switch (_solution)
    {
    case 1:
        return BinarySearch_33(nums, target);
    default:
        return -1; // 確保所有路徑都有回傳值
    }

    return -1;
}

int BinarySearch::BinarySearch_33(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + right >> 1;
        if (nums[mid] > target) right = mid - 1;
        else if (nums[mid] < target) left = mid + 1;
        else return mid;
    }
    return left;
}
#pragma endregion

#pragma endregion




