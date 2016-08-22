def partition(num, left, right):
	lp, rp = left, right
	key = num[right]
	while lp < rp:
		while num[lp] < key:
			lp = lp + 1
		while num[rp] >= key and rp > lp:
			rp = rp - 1
		if lp >= rp:
			break
		num[lp], num[rp] = num[rp], num[lp]
	num[lp], num[right] = num[right], num[lp]
	return lp


def quickSort(num, left, right):
	if left < right:
		split = partition(num, left, right)
		quickSort(num, left, split - 1)
		quickSort(num, split + 1, right)


if __name__ == '__main__':
	import random
	a = []
	for idx in range(100):
		a.append(random.randint(0,100))
	print a
	quickSort(a, 0, len(a) - 1)
	print "After Sort:"
	print a
	flag = True
	for idx in range(1, len(a)):
		if a[idx] < a[idx - 1]:
			flag = False
			break

	print flag


