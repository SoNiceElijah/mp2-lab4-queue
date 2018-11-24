#include "queue.h"
#include <gtest.h>

TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue<int> q(5));
}

TEST(TQueue, throw_when_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue<int> q(-5));
}

TEST(TQueue, can_push)
{
	TQueue<int> q(5);
	ASSERT_NO_THROW(q.Push(4));
}

TEST(TQueue, can_shift)
{
	TQueue<int> q(5);
	q.Push(4);
	q.Push(2);
	EXPECT_EQ(4, q.Shift());
}

TEST(TQueue, can_not_shift_empty_queue)
{
	TQueue<int> q(5);
	ASSERT_ANY_THROW(q.Shift(););
}

TEST(TQueue, can_not_push_full_queue)
{
	TQueue<int> q(5);
	q.Push(2);
	q.Push(2);
	q.Push(2);
	q.Push(2);
	q.Push(2);
	ASSERT_ANY_THROW(q.Push(2));
}

