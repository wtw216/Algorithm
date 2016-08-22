def insertionSort(num):
	for idx in range(1, len(num)):
		if num[idx - 1] > num[idx]:
			temp = num[idx]
			pos = idx
			while pos > 0 and num[pos - 1] > temp:
				num[pos] = num[pos - 1]
				pos = pos - 1
			num[pos] = temp

	
if __name__ == '__main__':
	import random
	a = []
	for idx in range(100):
		a.append(random.randint(0,100))
	print a
	insertionSort(a)
	print "After Sort:"
	print a
	flag = True
	for idx in range(1, len(a)):
		if a[idx] < a[idx - 1]:
			flag = False
			break

	print flag


