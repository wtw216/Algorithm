def selectionSort(num):
	p = 0
	while p < len(num):
		MIN_POS = p
		MIN = num[MIN_POS]
		for idx in range(p + 1, len(num)):
			if num[idx] < MIN:
				MIN_POS = idx
				MIN = num[idx]
		num[p], num[MIN_POS] = MIN, num[p]
		p = p + 1

if __name__ == '__main__':
	import random
	a = []
	for idx in range(100):
		a.append(random.randint(0,100))
	print a
	selectionSort(a)
	print "After Sort:"
	print a
	flag = True
	for idx in range(1, len(a)):
		if a[idx] < a[idx - 1]:
			flag = False
			break

	print flag


