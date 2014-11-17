def merge(left, right):
	inverse = 0
	result = []
	li, ri = 0, 0
	while li < len(left) and ri < len(right):
		if left[li] <= right[ri]:
			result.append(left[li])
			li += 1
		else:
			result.append(right[ri])
			ri += 1
			inverse += len(left) - li
	result.extend(left[li:])
	result.extend(right[ri:])
	return result, inverse

def inversion(m):
	if len(m) <= 1:
		return m, 0
 
	middle = len(m) / 2
	left = m[:middle]
	right = m[middle:]
 
	left, inverseL = inversion(left)
	right, inverseR = inversion(right)
	mm, inverseM = merge(left, right)
	return mm, inverseM+inverseL+inverseR

N = int(raw_input())
A = [int(a) for a in raw_input().split()]
print inversion(A)[1]
