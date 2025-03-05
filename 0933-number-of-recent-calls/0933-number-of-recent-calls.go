type RecentCounter struct {
    requests []int
}

func Constructor() RecentCounter {
    return RecentCounter{}
}

func (this *RecentCounter) Ping(t int) int {
    this.requests = append(this.requests, t)

    for this.requests[0] < t-3000 {
        this.requests = this.requests[1:]
    }

    return len(this.requests)
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */