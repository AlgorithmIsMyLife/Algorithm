class Solution:
    def getPre(self, nums:List[int]) -> List[int]:
        prelist = []
        product = 1
        for i in nums:
            prelist.append(product)
            product *= i
        return prelist

    def getPost(self, nums:List[int]) -> List[int]:
        postlist = []
        product = 1
        for i in reversed(nums):
            postlist.append(product)
            product *= i
        return list(reversed(postlist))


    def productExceptSelf(self, nums: List[int]) -> List[int]:
        pre = Solution.getPre(Solution,nums)
        post = Solution.getPost(Solution,nums)
        productList = []
        for i in range(len(nums)):
            productList.append(pre[i] * post[i])
        return productList