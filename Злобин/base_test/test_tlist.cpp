#include "list.h"
#include <gtest.h>

TEST(List, can_create_list)
{
	ASSERT_NO_THROW(List<double> l());
}

TEST(List, can_copy_list)
{
	List<double> l(2);
	ASSERT_NO_THROW(List<double> list(l));
}

TEST(List, can_add_link)
{
	List<double> l(5);
	ASSERT_NO_THROW(l.Insert(1));
}

TEST(List, can_delete_link_by_key)
{
	List<double> l(5);
	ASSERT_NO_THROW(l.Delete(5.0));
}

TEST(List, can_delete_link_by_index)
{
	List<double> l(5);
	ASSERT_NO_THROW(l.Delete(0));
}

TEST(List, the_list_is_empty)
{
	List<double> l(5);
	l.Delete(5);
	EXPECT_EQ(1, l.Length());
}

TEST(List, can_get_key_by_index)
{
	List<double> l(5);
	l.Insert(3);
	l.Insert(1);
	EXPECT_EQ(1, l[2]);
}