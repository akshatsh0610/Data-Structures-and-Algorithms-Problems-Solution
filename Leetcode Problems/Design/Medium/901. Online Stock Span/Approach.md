# Problem Statement

Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The **span** of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was 
less than or equal to the price of that day.

- For example, if the prices of the stock in the last four days is `[7,2,1,2]` and the price of the stock today is `2`, then the span of today is `4` because
  starting from today, the price of the stock was less than or equal `2` for `4` consecutive days.

- Also, if the prices of the stock in the last four days is `[7,34,1,2]` and the price of the stock today is `8`, then the span of today is `3` because starting
  from today, the price of the stock was less than or equal `8` for `3` consecutive days.

  Implement the `StockSpanner` class:

  - `StockSpanner()` Initializes the object of the class.
  - `int next(int price)` Returns the span of the stock's price given that today's price is `price`.

# Example

**Input** 

`["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]`
`[[], [100], [80], [60], [70], [60], [75], [85]]`

**Output**

`[null, 1, 1, 1, 2, 1, 4, 6]`

**Explanation**

`StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6`

# Problem Constraints

- `1 <= price <= 10^5`
- At most `10^4` calls will be made to `next`.

# Topic Tags

`Stack`, `Design`, `Monotonic Stack`, `Data Stream`

# Intuition

The problem says that we are given the **price** of stock on a particular day and we have to return the **span** of that stock. The **span** is the number of
**consecutive days** for which the price of stock is **less or equal to** the current day price. 

The problem is a variation of **Next smaller element on left**. We will use **stack** that will store the price of stock of former days. When the current price 
of stock comes we will calculate the **span** by checking the previous days price in stack. If `st.top()<=current price` then this is our desired day otherwise
we will stop checking and will store the current price in stack.
