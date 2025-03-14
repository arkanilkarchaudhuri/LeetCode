def check(piles, h, mid)
  ans = 0
  piles.each do |pile|
    ans += pile / mid
    ans += 1 if pile % mid != 0
  end
  ans <= h
end
def min_eating_speed(piles, h)
  low = 1
  high = piles.max
  while low < high
    mid = (low + high) / 2
    if check(piles, h, mid)
      high = mid
    else
      low = mid + 1
    end
  end
  low
end