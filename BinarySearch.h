#pragma once

#define Build_DLL

#ifdef Build_DLL 
#define DLL_API _declspec(dllexport)
#else 
#define DLL_API _declspec(dllimport)
#endif // BuildDLL _declspec(DLLExport)

#include <string>
#include <iostream>
#include <vector>       // �Y�����ܼƥΨ� std::vector
#include <map>          // �Y�� std::map �ܼ�
#include <unordered_map>// �Y�� std::unordered_map �ܼ�

class BinarySearch {
private:
    int* data;  // ���]��Ʀ����O����

public:
    // �w�]�غc��
    BinarySearch();

    // �a�Ѽƫغc��
    BinarySearch(int value);

    // �Ѻc��
    ~BinarySearch();

    // ��k�G�]�w��
    void setData(int value);

    // ��k�G���o��
    int getData() const;

    // ��ܸ��
    void display() const;

    // ======= Leetcode Solutions =======
    int Leetcode_Sol_704(std::vector<int>& nums, int target, int _solution);
    int BinarySearch_704(std::vector<int>& nums, int target);

    int Leetcode_Sol_35(std::vector<int>& nums, int target, int _solution);
    int BinarySearch_35(std::vector<int>& nums, int target);

    int Leetcode_Sol_33(std::vector<int>& nums, int target, int _solution);
    int DoubleBinarySearch_33(std::vector<int>& nums, int target);
    int OnceBinarySearchForLeft_33(std::vector<int>& nums, int target);//*****(�۷��Trapping Rain Water���D)
    int OnceBinarySearchForRight_33(std::vector<int>& nums, int target);//*****(�۷��Trapping Rain Water���D)

    int Leetcode_Sol_278(int n, int _solution);
    int BinarySearchLeftapproach_278(int n);
    int BinarySearchRightapproach_278(int n);
    bool isBadVersion(int n);

    int Leetcode_Sol_69(int x, int _solution);
    int BinarySearchforbitoperator_69(int x);
    int BinarySearchdivior_69(int x);

    int Leetcode_Sol_374(int n, int _solution);
    int BinarySearchBoundaryfinding_374(int n);
    int BinarySearchsurevalue_374(int n);
    int guess(int n);

    int Leetcode_Sol_162(std::vector<int>& nums, int _solution);
    int BinarySearch_162(std::vector<int>& nums);

    std::vector<int> Leetcode_Sol_34(std::vector<int>& nums, int target, int _solution);//*****
    std::vector<int> BinarySearch_34(std::vector<int>& nums, int target);
    std::vector<int> DoubleBinarySearch_34(std::vector<int>& nums, int target);//*****
    std::vector<int> Mylower_bound_34(std::vector<int>& nums, int target);//*****
    std::vector<int> stdlower_bound_34(std::vector<int>& nums, int target);

    bool Leetcode_Sol_81(std::vector<int>& nums, int target, int _solution);
    bool DoubleBinarySearch_81(std::vector<int>& nums, int target);
    bool OnceBinarySearchForLeft_81(std::vector<int>& nums, int target);//*****(�۷��Trapping Rain Water���D)
    bool OnceBinarySearchForRight_81(std::vector<int>& nums, int target);//*****(�۷��Trapping Rain Water���D)

    int Leetcode_Sol_153(std::vector<int>& nums, int _solution);
    int BinarySearch_153(std::vector<int>& nums);//*****(�n�`�N���ĮɡA�n�Τ���P�_)

    int Leetcode_Sol_154(std::vector<int>& nums, int _solution);
    int BinarySearch_154(std::vector<int>& nums);

    int Leetcode_Sol_875(std::vector<int>& piles, int h, int _solution);//*****
    int BinarySearch_1_875(std::vector<int>& piles, int h);
    int BinarySearch_2_875(std::vector<int>& piles, int h);

    int Leetcode_Sol_1011(std::vector<int>& weights, int days, int _solution);//*****
    int BinarySearch_1_1011(std::vector<int>& weights, int days);
    int BinarySearch_2_1011(std::vector<int>& weights, int days);

    int Leetcode_Sol_1283(std::vector<int>& nums, int threshold, int _solution);
    int BinarySearch_1_1283(std::vector<int>& nums, int threshold);
    int BinarySearch_2_1283(std::vector<int>& nums, int threshold);

    int Leetcode_Sol_410(std::vector<int>& nums, int k, int _solution);
    int BinarySearch_1_410(std::vector<int>& nums, int k);
    int BinarySearch_2_410(std::vector<int>& nums, int k);
    int DP_410(std::vector<int>& nums, int k);

    double Leetcode_Sol_4(std::vector<int>& nums1, std::vector<int>& nums2, int _solution);//*****
    double MergeSortOfDivideandConquer_4(std::vector<int>& nums1, std::vector<int>& nums2);
    double TwoPointer_4(std::vector<int>& nums1, std::vector<int>& nums2);
    double BinarySearch_4(std::vector<int>& nums1, std::vector<int>& nums2);




    


    // ======= Leetcode Solutions =======

};



extern DLL_API BinarySearch BinarySearchInstance;
