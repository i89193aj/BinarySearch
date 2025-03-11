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


#pragma region 技巧
/*
        1.二分搜尋適用的問題通常有這些特徵：
          數據有序（或可以轉化成某種有序關係）
          可以定義一個明確的「單調性條件」，例如 f(x) 是遞增或遞減的
          答案可以通過「判斷一個條件」來逼近
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
            "return left" + (left + right) >> 1(小中值)：(從左邊收斂，所以盡量用nums[right]來比較nums[mid])
            "left = mid + 1" + "right = mid"
            "return right" + (left + right + 1) >> 1(大中值)：(從右邊收斂，所以盡量用nums[left]來比較nums[mid])
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

#pragma region 考題一:基礎二分搜尋

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

#pragma endregion

#pragma region 考型：變體二分搜尋（lower_bound, upper_bound）

#pragma region Leetcode 278. First Bad Version
//Leetcode 278. First Bad Version
int BinarySearch::Leetcode_Sol_278(int n, int _solution) {
    switch (_solution)
    {
    case 1:
        return BinarySearchLeftapproach_278(n);
    case 2:
        return BinarySearchRightapproach_278(n);
    default:
        return -1; // 確保所有路徑都有回傳值
    }

    return-1;
}
/*左側逼近*/
int BinarySearch::BinarySearchLeftapproach_278(int n) {
    int left = 0, right = n;
    while (left < right) {
        long long mid = (long)left + right >> 1;
        if (!isBadVersion(mid)) left = mid + 1;
        else right = mid;
    }
    return left;
}
/*右側逼近*/
int BinarySearch::BinarySearchRightapproach_278(int n) {
    int left = 0, right = n;
    while (left < right) {
        long long mid = (long)left + right + 1 >> 1;
        if (isBadVersion(mid)) right = mid - 1;
        else left = mid;
    }
    return right + 1;
}

bool BinarySearch::isBadVersion(int _version) {
    int badversion_start = 4;
    return _version == 4 ? true : false;
}

#pragma endregion

#pragma region Leetcode 69. Sqrt(x)
//Leetcode 69. Sqrt(x)
int BinarySearch::Leetcode_Sol_69(int x, int _solution) {
    switch (_solution)
    {
    case 1:
        return BinarySearchforbitoperator_69(x);
    case 2:
        return BinarySearchdivior_69(x);
    default:
        return -1; // 確保所有路徑都有回傳值
    }

    return-1;
}
/*bit operator*/
int BinarySearch::BinarySearchforbitoperator_69(int x) {
    int left = 0, right = (1 << 16) - 1;//2^16 * 2^16 = 2^32 => (2^16)-1為此題目最大根號值
    while (left < right) {
        int mid = (left + right) >> 1;
        if ((long)mid * mid < x) left = mid + 1;
        else right = mid;
    }

    return (long)left * left > x ? left - 1 : left;
}

/*division*/
int BinarySearch::BinarySearchdivior_69(int x) {
    if (!x) return 0;//如果你要用除法，請注意所有除數可能為"0"的可能 => int left != 0
    int left = 1, right = x;
    while (left <= right) {
        int mid = left + (right - left >> 1);//int mid = left+right>>1; x=2147483647=>int會爆開
        if (mid == x / mid) return mid;
        else if (mid > x / mid) right = mid - 1;
        else left = mid + 1;
    }

    return right;
}
#pragma endregion

#pragma region Leetcode 374. Guess Number Higher or Lower
//Leetcode 374. Guess Number Higher or Lower
int BinarySearch::Leetcode_Sol_374(int x, int _solution) {
    switch (_solution)
    {
    case 1:
        return BinarySearchBoundaryfinding_374(x);
    case 2:
        return BinarySearchsurevalue_374(x);
    default:
        return -1; // 確保所有路徑都有回傳值
    }

    return-1;
}
/*用邊界找尋*/
int BinarySearch::BinarySearchBoundaryfinding_374(int n) {
    int left = 1, right = n;
    while (left <= right) {
        //int mid = left + (right - left)/2;這種如果數字大，那就會慢，因為會多做幾次(right - left)
        long mid = (long)right + left >> 1;
        if (guess(mid) == 1) left = mid + 1;
        else if (guess(mid) == -1) right = mid - 1;
        else return mid;
    }
    return left;
}

/*確定值在裡面*/
int BinarySearch::BinarySearchsurevalue_374(int n) {
    int left = 1, right = n;
    while (left < right) {
        int mid = left + ((right - left) >> 1);
        if (guess(mid) == 1) left = mid + 1;
        else right = mid;
    }
    return left;
}

int BinarySearch::guess(int guessnum) {
    int ans = 6;
    return ans == guessnum ? 0 : (ans > guessnum ? -1 : 1);
}
#pragma endregion

#pragma region Leetcode 162. Find Peak Element
//Leetcode 162. Find Peak Element
int BinarySearch::Leetcode_Sol_162(vector<int>& nums, int _solution) {
    switch (_solution)
    {
    case 1:
        return BinarySearch_162(nums);
    default:
        return -1; // 確保所有路徑都有回傳值
    }

    return-1;
}

/*考點：1.判斷的條件 2.有無值)*/
int BinarySearch::BinarySearch_162(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + right >> 1;
        if (nums[mid] < nums[mid + 1]) left = mid + 1;
        else right = mid;
    }
    return left;
    /*
        如果 nums[mid] < nums[mid + 1]，則 peak 一定在右側，所以我們讓 left = mid + 1。
        否則 peak 在左側或當前 mid 位置，所以我們讓 right = mid，而不是 mid + 1，避免錯誤跳過 peak。
    */
}
#pragma endregion

#pragma endregion

#pragma region 考型三：二分搜尋 + 數學優化 (旋轉數組 & 變體)

#pragma region Leetcode 33. Search in Rotated Sorted Array
//Leetcode 33. Search in Rotated Sorted Array
int BinarySearch::Leetcode_Sol_33(std::vector<int>& nums, int target, int _solution) {
    switch (_solution)
    {
    case 1:
        return DoubleBinarySearch_33(nums, target);
    case 2:
        return OnceBinarySearchForLeft_33(nums, target);
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
    if (target >= nums[left] && target <= nums[nums.size() - 1])  // nums[left] <= target <= nums[n-1] ，left 不動 (錯誤：if(target < nums[0])不能只靠這個判別，沒旋轉會出問題)      
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
/*技巧：只需要確保 target 落在有序的一邊！(一定至少一邊有序)*/
/*最佳化寫法 (只用一個 Binary Search)，以左邊判斷*/
int BinarySearch::OnceBinarySearchForLeft_33(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + right >> 1;
        if (nums[mid] == target)return mid;
        if (nums[mid] < nums[left]) {// 最小值在左邊(右邊有序)
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
        else {// 最小值在右邊(左邊有序)
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
    }
    return -1;
}
/*最佳化寫法 (只用一個 Binary Search)，以右邊判斷*/
int BinarySearch::OnceBinarySearchForRight_33(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + right >> 1;
        if (nums[mid] == target) return mid;

        if (nums[mid] > nums[right]) {
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else {
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}
#pragma endregion

#pragma region Leetcode 81. Search in Rotated Sorted Array II
//Leetcode 81. Search in Rotated Sorted Array II
bool BinarySearch::Leetcode_Sol_81(std::vector<int>& nums, int target, int _solution) {
    switch (_solution)
    {
    case 1:
        return DoubleBinarySearch_81(nums, target);
    case 2:
        return OnceBinarySearchForRight_81(nums, target);
    case 3:
        return OnceBinarySearchForLeft_81(nums, target);

    default:
        return -1; // 確保所有路徑都有回傳值
    }

    return-1;
}

bool BinarySearch::DoubleBinarySearch_81(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    // 找到旋轉點（最小值位置）
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        }
        else if (nums[mid] < nums[right]) {
            right = mid;
        }
        else {
            // nums[mid] == nums[right]，無法確定方向，但不能影響 pivot
            if (right > 0 && nums[right] >= nums[right - 1]) {
                right--;
            }
            else {
                left = right;
                break;
            }
        }
    }
    int pivot = left;  // 旋轉點（最小值索引）

    // 根據 target 判斷搜尋範圍
    left = 0, right = nums.size() - 1;
    if (nums[pivot] <= target && target <= nums[right]) {
        left = pivot;
    }
    else {
        right = pivot - 1;
    }

    // 二分搜尋
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        }
        else if (nums[mid] > target) {
            right = mid - 1;
        }
        else {
            return true;
        }
    }
    return false;
}

/*最佳化寫法 (只用一個 Binary Search)，以右邊判斷*/
bool BinarySearch::OnceBinarySearchForRight_81(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return true;

        // **修改這行：判斷是否左半部無序**
        if (nums[mid] > nums[right]) {
            // 代表左半部有序，右半部無序
            if (nums[left] <= target && target < nums[mid]) {  // target 在左半邊
                right = mid - 1;
            }
            else {  // target 在右半邊
                left = mid + 1;
            }
        }
        else if (nums[mid] < nums[right]) {
            // 右半邊是有序的
            if (nums[mid] < target && target <= nums[right]) {  // target 在右半邊
                left = mid + 1;
            }
            else {  // target 在左半邊
                right = mid - 1;
            }
        }
        else {
            // `nums[mid] == nums[right]`，無法確定哪邊是有序的，縮減範圍
            right--;
        }
    }

    return false;
}

/*最佳化寫法 (只用一個 Binary Search)，以左邊判斷*/
bool BinarySearch::OnceBinarySearchForLeft_81(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return true; // 找到 target，直接回傳

        // **關鍵：處理重複元素**
        if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
            left++;
            right--;
            continue;  // 跳過這次迴圈，繼續搜尋
        }

        // **判斷哪一半是有序的**
        if (nums[left] <= nums[mid]) {  // 左半部有序
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;  // target 在左半部
            }
            else {
                left = mid + 1;  // target 在右半部
            }
        }
        else {  // 右半部有序
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;  // target 在右半部
            }
            else {
                right = mid - 1;  // target 在左半部
            }
        }
    }
    return false;  // 沒找到
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

#pragma region Leetcode 154. Find Minimum in Rotated Sorted Array II
//Leetcode 154. Find Minimum in Rotated Sorted Array II
int BinarySearch::Leetcode_Sol_154(std::vector<int>& nums, int _solution) {
    switch (_solution)
    {
    case 1:
        return BinarySearch_154(nums);
    default:
        return -1; // 確保所有路徑都有回傳值
    }

    return -1;
}

/*考點：1.是否值在vector裡面 => while (left < right) 2. 考要找左邊界還是右邊界right = mid or right = mid - 1*/
int BinarySearch::BinarySearch_154(std::vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + right >> 1;
        if (nums[mid] > nums[right]) left = mid + 1;
        else if (nums[mid] < nums[right]) right = mid;
        else right--;
    }
    return nums[left];
}
#pragma endregion

#pragma endregion






