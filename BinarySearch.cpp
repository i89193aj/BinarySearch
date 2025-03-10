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
          a.迴圈判斷式：while(left<=right)
          b."left = middle + 1" + "right = middle - 1"(>= 走這) <=> left + 小中值(left + right) >> 1：(從右邊收斂)
            "right = middle - 1" + "left = middle + 1"(<= 走這) <=> right + 大中值(left + right + 1) >> 1：(從左邊收斂)
            (用後者去逼近target，這樣前者就會是第一次出現的target值)
          vector一定有要找的值:
          a.迴圈判斷式：1.while(left < right) 
          b."left = middle + 1" + "right = middle" <=> left + 小中值(left + right) >> 1：(從左邊收斂)
            "right = middle - 1" + "left = middle" <=> right + 大中值(left + right + 1) >> 1：(從右邊收斂)
            (換句話說：
            left + (left + right) >> 1(小中值)：(從左邊收斂)
            "left = mid + 1" + "right = mid"
            right + (left + right + 1) >> 1(大中值)：(從右邊收斂)
            "right = mid - 1" + "left = mid")
                   
          大部分：
          "left = mid + 1" + "right = mid"　

          if(nums[mid] > target)(這個能知道要不要留middle)：
          right = mid - 1 和 right = mid 的選擇，取決於 mid 是否還可能是答案：
          如果 mid 確定不是答案，應該完全排除 (right = mid - 1)
          如果 mid 可能是答案，不能直接排除 (right = mid)

        3.確定寫的東西一定有收斂

        4.大多題目都是return left：因為：middle = (小中值)
        原因：int middle = (right + left) >> 1;的關係，所以right有機會跳過答案
        在偶數對情況下：middle = 左側最大值(簡稱：小中值)，所以left不會跳過(因為條件判斷式：都是用num[mid]判斷
        在奇數對情況下：奇數對不談，因為對稱

        理解：
        用兩個數字去想 nums[1] vs nums[2] => 那麼小中值就會是nums[1]；大中值就會是nums[2]
        那當我要取最小值的時候，但卻用left+大中值，那會找不到邊界
        所以我要們要嘛配left + 小中值 or right + 大中值；另一邊就會幫忙擋住到當前大小中值
        (但因為不知道mid下一個值有沒有比較大or小，所以就直接等於(大or小)中值)


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

#pragma region Leetcode 153. Find Minimum in Rotated Sorted Array
//Leetcode 153. Find Minimum in Rotated Sorted Array
int BinarySearch::Leetcode_Sol_153(std::vector<int>& nums, int _solution) {
    switch (_solution)
    {
    case 1:
        return BinarySearch_153(nums);
    default:
        return -1; // 確保所有路徑都有回傳值
    }

    return -1;
}

/*考點：1.是否值在vector裡面 => while (left < right) 2. 考要找左邊界還是右邊界right = mid or right = mid - 1*/
int BinarySearch::BinarySearch_153(std::vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + right >> 1;
        if (nums[mid] > nums[right]) left = mid + 1;
        else right = mid;
    }
    return nums[left];
}
#pragma endregion

#pragma region Leetcode 34. Find First and Last Position of Element in Sorted Array
//Leetcode 34. Find First and Last Position of Element in Sorted Array
vector<int> BinarySearch::Leetcode_Sol_34(std::vector<int>& nums, int target, int _solution) {
    switch (_solution)
    {
    case 1:
        return BinarySearch_34(nums, target);
    case 2:
        return DoubleBinarySearch_34(nums, target);
    case 3:
        return Mylower_bound_34(nums, target);
    case 4:
        return stdlower_bound_34(nums, target);
    default:
        return {}; // 確保所有路徑都有回傳值
    }

    return {};
}
/*最壞情況O(n)，ex：target = 8, vector = {8,8,8,8,8,8}*/
vector<int> BinarySearch::BinarySearch_34(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int start = -1, end = -1;
    vector<int> ans;
    while (left <= right) {
        int mid = right + left >> 1;
        if (nums[mid] > target) right = mid - 1;
        else if (nums[mid] < target) left = mid + 1;
        else {
            right = mid;
            left = mid;
            while (left > -1 && nums[left] == target) {
                start = left;
                left--;
            }

            while (right < nums.size() && nums[right] == target) {
                end = right;
                right++;
            }
            break;
        };
    }
    return vector<int> {start, end};
}

vector<int> BinarySearch::DoubleBinarySearch_34(std::vector<int>& nums, int target) {
    if (nums.empty()) return { -1,-1 };
    int left = 0, right = nums.size() - 1;
    int start = -1, end = -1;
    while (left < right) {
        int mid = left + right >> 1;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }


    if (nums[left] != target) return vector<int> {start, end};

    start = left;
    right = nums.size() - 1;
    while (left < right) {
        int mid = left + right + 1 >> 1;
        if (nums[mid] > target) right = mid - 1;
        else left = mid;
    }
    end = right;
    return vector<int> {start, end};
}

vector<int> BinarySearch::Mylower_bound_34(std::vector<int>& nums, int target) {
    auto Mylower_bound = [&](vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    };
    int low = 0, high = nums.size() - 1;
    int startingPosition = Mylower_bound(nums, low, high, target);
    int endingPosition = Mylower_bound(nums, low, high, target + 1) - 1;
    if (startingPosition < nums.size() && nums[startingPosition] == target) {
        return { startingPosition, endingPosition };
    }
    return { -1, -1 };
}

vector<int> BinarySearch::stdlower_bound_34(std::vector<int>& nums, int target) {
    int startingPosition = std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int endingPosition = std::lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin() - 1;
    if (startingPosition < nums.size() && nums[startingPosition] == target) {
        return { startingPosition, endingPosition };
    }
    return { -1, -1 };
}
#pragma endregion

#pragma region Leetcode 33. Search in Rotated Sorted Array
//Leetcode 33. Search in Rotated Sorted Array
int BinarySearch::Leetcode_Sol_33(std::vector<int>& nums, int target, int _solution) {
    switch (_solution)
    {
    case 1:
        return DoubleBinarySearch_33(nums, target);
    default:
        return -1; // 確保所有路徑都有回傳值
    }

    return-1;
}
/*double binary search*/
int BinarySearch::DoubleBinarySearch_33(std::vector<int>& nums, int target) {
    //step. 1 先找到最小值
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + right >> 1;
        if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;      
    }
    //這時候nums[left] = 最小值，left = pivot(旋轉點)
    if (target >= nums[left] && target <= nums[nums.size()-1])  // nums[left] <= target <= nums[n-1] ，left 不動 (錯誤：if(target < nums[0])不能只靠這個判別，沒旋轉會出問題)      
        right = nums.size() - 1;
    else {                                         // nums[0] <= target <= nums[left - 1]
        right = left - 1;
        left = 0;
    }
    while (left <= right) {
        int mid = left + right >> 1;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}

int BinarySearch::OnceBinarySearch_33(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + right >> 1;

        if (nums[mid] == target) return mid; // 找到直接回傳

        // 確認 mid 位於左半部（沒有旋轉的部分）
        if (nums[mid] >= nums[left]) {
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1; // target 在左半部
            else
                left = mid + 1;  // target 在右半部
        }
        // mid 位於右半部（已旋轉的部分）
        else {
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;  // target 在右半部
            else
                right = mid - 1; // target 在左半部
        }
    }

    return -1; // 沒找到
}



#pragma endregion
#pragma endregion




