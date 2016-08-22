def merge(num, left, right):
	middle = (left + right) / 2
	l1 = num[left : middle + 1]
	l2 = num[middle + 1 : right + 1]
	new = []
	idx1, idx2 = 0, 0
	while idx1 < len(l1) and idx2 < len(l2):
		if l1[idx1] < l2[idx2]:
			new.append(l1[idx1])
			idx1 = idx1 + 1
		else:
			new.append(l2[idx2])
			idx2 = idx2 + 1
	if idx1 == len(l1):
		while idx2 < len(l2):
			new.append(l2[idx2])
			idx2 = idx2 + 1
	if idx2 == len(l2):
		while idx1 < len(l1):
			new.append(l1[idx1])
			idx1 = idx1 + 1

	num[left: right + 1] = new[:]

def mergeSort(num, left, right):
	if left < right:
		middle = (left + right) / 2
		mergeSort(num, left, middle)
		mergeSort(num, middle + 1, right)
		merge(num, left, right)

if __name__ == '__main__':
	import random
	a = []
	for idx in range(100):
		a.append(random.randint(0,100))
	print a
	mergeSort(a, 0, len(a) - 1)
	print "After Sort:"
	print a
	flag = True
	for idx in range(1, len(a)):
		if a[idx] < a[idx - 1]:
			flag = False
			break

	print flag


