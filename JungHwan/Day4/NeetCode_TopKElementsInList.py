class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = []
        #immutable하도록 tuple로 저장
        for i in nums:
            freq.append((i, nums.count(i)))
        #중복 제거
        freq = list(set(freq))
        #value 크기순 내림차순 정렬
        freq.sort(key = lambda x: x[1], reverse = True)
        #앞에서부터 k개만 value 추출
        return list(map(lambda x: x[0], freq[0:k]))

        