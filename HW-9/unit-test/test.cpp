#include "pch.h"
#include <memory>
#include "../Circle.h"
#include "../Triangle.h"
#include "../Square.h"
#include "../Drawing.h"

TEST(should_PrintTriangle, TrianglePrintTest)
{
	const Drawing triangle{MakeTriangle( 3.3 )};

	testing::internal::CaptureStdout();
	triangle.drawShape();
	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(output, "Triangle /_\\\n") << "Invalid output string.";
}

TEST(should_PrintCircle, CirclePrintTest)
{
	const Drawing circle{MakeCircle()};

	testing::internal::CaptureStdout();
	circle.drawShape();
	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(output, "Circle o\n") << "Invalid output string.";
}

TEST(should_PrintSquare, SquarePrintTest)
{
	const Drawing square{MakeSquare()};

	testing::internal::CaptureStdout();
	square.drawShape();
	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(output, "Square |_|\n") << "Invalid output string.";
}

TEST(should_PrintTriangleArea, TriangleAreaPrintTest)
{
	const Drawing triangle1{ MakeTriangle(3.0, 5.5, 2.6) };
	testing::internal::CaptureStdout();
	triangle1.printArea();
	std::string output1 = testing::internal::GetCapturedStdout();

	const Drawing triangle2{ MakeTriangle(1.0, 1.0, 1.0) };
	testing::internal::CaptureStdout();
	triangle2.printArea();
	std::string output2 = testing::internal::GetCapturedStdout();

	const Drawing triangle3{ MakeTriangle(2.75, 2.75, 5.0) };
	testing::internal::CaptureStdout();
	triangle3.printArea();
	std::string output3 = testing::internal::GetCapturedStdout();

	Drawing triangle4{ MakeTriangle(100.0, 100.0, 100.0) };
	testing::internal::CaptureStdout();
	triangle4.printArea();
	std::string output4 = testing::internal::GetCapturedStdout();

	EXPECT_EQ(output1, "The area is: 1.44482\n") << "Invalid output string.";
	EXPECT_EQ(output2, "The area is: 0.433013\n") << "Invalid output string.";
	EXPECT_EQ(output3, "The area is: 2.86411\n") << "Invalid output string.";
	EXPECT_EQ(output4, "The area is: 4330.13\n") << "Invalid output string.";
}


TEST(should_PrintCircleArea, CircleAreaPrintTest)
{
	const Drawing circle1{ MakeCircle(2.0) };
	testing::internal::CaptureStdout();
	circle1.printArea();
	std::string output1 = testing::internal::GetCapturedStdout();

	const Drawing circle2{ MakeCircle(2.185) };
	testing::internal::CaptureStdout();
	circle2.printArea();
	std::string output2 = testing::internal::GetCapturedStdout();

	const Drawing circle3{ MakeCircle(100.0) };
	testing::internal::CaptureStdout();
	circle3.printArea();
	std::string output3 = testing::internal::GetCapturedStdout();

	Drawing circle{ MakeCircle(2.5) };
	testing::internal::CaptureStdout();
	circle.printArea();
	std::string output4 = testing::internal::GetCapturedStdout();

	EXPECT_EQ(output1, "The area is: 12.5664\n") << "Invalid output string.";
	EXPECT_EQ(output2, "The area is: 14.9987\n") << "Invalid output string.";
	EXPECT_EQ(output3, "The area is: 31415.9\n") << "Invalid output string.";
	EXPECT_EQ(output4, "The area is: 19.635\n") << "Invalid output string.";
}

TEST(should_PrintSquareArea, SquareAreaPrintTest)
{
	const Drawing square1{ MakeSquare(2) };
	testing::internal::CaptureStdout();
	square1.printArea();
	std::string output1 = testing::internal::GetCapturedStdout();

	const Drawing square2{ MakeSquare(0) };
	testing::internal::CaptureStdout();
	square2.printArea();
	std::string output2 = testing::internal::GetCapturedStdout();

	const Drawing square3{ MakeSquare(7.5) };
	testing::internal::CaptureStdout();
	square3.printArea();
	std::string output3 = testing::internal::GetCapturedStdout();

	const Drawing square4{ MakeSquare(100.1) };
	testing::internal::CaptureStdout();
	square4.printArea();
	std::string output4 = testing::internal::GetCapturedStdout();

	EXPECT_EQ(output1, "The area is: 4\n") << "Invalid output string.";
	EXPECT_EQ(output2, "The area is: 0\n") << "Invalid output string.";
	EXPECT_EQ(output3, "The area is: 56.25\n") << "Invalid output string.";
	EXPECT_EQ(output4, "The area is: 10020\n") << "Invalid output string.";
}

int main(int ac, char* av[])
{
	testing::InitGoogleTest(&ac, av);
	return RUN_ALL_TESTS();
}