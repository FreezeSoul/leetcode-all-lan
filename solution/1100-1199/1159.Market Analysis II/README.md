# [1159. 市场分析 II](https://leetcode.cn/problems/market-analysis-ii)

[English Version](/solution/1100-1199/1159.Market%20Analysis%20II/README_EN.md)

## 题目描述

<!-- 这里写题目描述 -->

<p>表: <code>Users</code></p>

<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| user_id        | int     |
| join_date      | date    |
| favorite_brand | varchar |
+----------------+---------+
user_id 是该表的主键
表中包含一位在线购物网站用户的个人信息，用户可以在该网站出售和购买商品。
</pre>

<p>表: <code>Orders</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| order_date    | date    |
| item_id       | int     |
| buyer_id      | int     |
| seller_id     | int     |
+---------------+---------+
order_id 是该表的主键
item_id 是 Items 表的外键
buyer_id 和 seller_id 是 Users 表的外键
</pre>

<p>表: <code>Items</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| item_id       | int     |
| item_brand    | varchar |
+---------------+---------+
item_id 是该表的主键
</pre>

<p>&nbsp;</p>

<p>写一个 SQL 查询确定每一个用户按日期顺序卖出的第二件商品的品牌是否是他们最喜爱的品牌。如果一个用户卖出少于两件商品，查询的结果是 <code>no</code> 。</p>

<p>题目保证没有一个用户在一天中卖出超过一件商品</p>

<p>下面是查询结果格式的例子：</p>

<pre>
Users table:
+---------+------------+----------------+
| user_id | join_date  | favorite_brand |
+---------+------------+----------------+
| 1       | 2019-01-01 | Lenovo         |
| 2       | 2019-02-09 | Samsung        |
| 3       | 2019-01-19 | LG             |
| 4       | 2019-05-21 | HP             |
+---------+------------+----------------+

Orders table:
+----------+------------+---------+----------+-----------+
| order_id | order_date | item_id | buyer_id | seller_id |
+----------+------------+---------+----------+-----------+
| 1        | 2019-08-01 | 4       | 1        | 2         |
| 2        | 2019-08-02 | 2       | 1        | 3         |
| 3        | 2019-08-03 | 3       | 2        | 3         |
| 4        | 2019-08-04 | 1       | 4        | 2         |
| 5        | 2019-08-04 | 1       | 3        | 4         |
| 6        | 2019-08-05 | 2       | 2        | 4         |
+----------+------------+---------+----------+-----------+

Items table:
+---------+------------+
| item_id | item_brand |
+---------+------------+
| 1       | Samsung    |
| 2       | Lenovo     |
| 3       | LG         |
| 4       | HP         |
+---------+------------+

Result table:
+-----------+--------------------+
| seller_id | 2nd_item_fav_brand |
+-----------+--------------------+
| 1         | no                 |
| 2         | yes                |
| 3         | yes                |
| 4         | no                 |
+-----------+--------------------+

id 为 1 的用户的查询结果是 no，因为他什么也没有卖出
id为 2 和 3 的用户的查询结果是 yes，因为他们卖出的第二件商品的品牌是他们自己最喜爱的品牌
id为 4 的用户的查询结果是 no，因为他卖出的第二件商品的品牌不是他最喜爱的品牌
</pre>

## 解法

<!-- 这里可写通用的实现逻辑 -->

<!-- tabs:start -->

### **SQL**

```sql
# Write your MySQL query statement below
select
    u.user_id as seller_id,
    case
        when u.favorite_brand = i.item_brand then 'yes'
        else 'no'
    end as 2nd_item_fav_brand
from
    users u
    left join (
        select
            order_date,
            item_id,
            seller_id,
            rank() over(
                partition by seller_id
                order by
                    order_date
            ) as rk
        from
            orders
    ) o on u.user_id = o.seller_id
    and o.rk = 2
    left join items i on o.item_id = i.item_id;
```

<!-- tabs:end -->
