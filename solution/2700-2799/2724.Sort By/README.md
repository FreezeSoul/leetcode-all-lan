# [2724. Sort By](https://leetcode.cn/problems/sort-by)

[English Version](/solution/2700-2799/2724.Sort%20By/README_EN.md)

## 题目描述

<!-- 这里写题目描述 -->

<p>Given an array <code>arr</code> and a function <code>fn</code>, return a sorted array <code>sortedArr</code>. You can assume&nbsp;<code>fn</code>&nbsp;only returns numbers and those numbers determine the sort order of&nbsp;<code>sortedArr</code>. <code>sortedArray</code> must be sorted in <strong>ascending order</strong> by <code>fn</code> output.</p>

<p>You may assume that <code>fn</code> will never duplicate numbers for a given array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [5, 4, 1, 2, 3], fn = (x) =&gt; x
<strong>Output:</strong> [1, 2, 3, 4, 5]
<strong>Explanation:</strong> fn simply returns the number passed to it so the array is sorted in ascending order.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [{&quot;x&quot;: 1}, {&quot;x&quot;: 0}, {&quot;x&quot;: -1}], fn = (d) =&gt; d.x
<strong>Output:</strong> [{&quot;x&quot;: -1}, {&quot;x&quot;: 0}, {&quot;x&quot;: 1}]
<strong>Explanation:</strong> fn returns the value for the &quot;x&quot; key. So the array is sorted based on that value.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> arr = [[3, 4], [5, 2], [10, 1]], fn = (x) =&gt; x[1]
<strong>Output:</strong> [[10, 1], [5, 2], [3, 4]]
<strong>Explanation:</strong> arr is sorted in ascending order by number at index=1.&nbsp;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>arr is a valid JSON array</code></li>
	<li><code>fn is a function that returns a number</code></li>
	<li><code>1 &lt;=&nbsp;arr.length &lt;= 5 * 10<sup>5</sup></code></li>
</ul>

## 解法

<!-- 这里可写通用的实现逻辑 -->

<!-- tabs:start -->

### **TypeScript**

<!-- 这里可写当前语言的特殊实现逻辑 -->

```ts
function sortBy(arr: any[], fn: Function): any[] {
    return arr.sort((a, b) => fn(a) - fn(b));
}
```

<!-- tabs:end -->
