# https://leetcode.com/problems/course-schedule/

# Runtime: 108 ms, faster than 33.11% of Python3 online submissions for Course Schedule.
# Memory Usage: 15.5 MB, less than 75.08% of Python3 online submissions for Course Schedule.

from typing import List

class Course:
    def __init__(self):
        self.depends_on = []
        # NOTE, one course can depends on multiple course.
        # So after studying one unblock course doesn't necessarily unblocks the next course
        self.unblocks = []

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        all_courses = {}

        for prerequisites in prerequisites:
            course_id, prereq_course_id = prerequisites

            if course_id in all_courses:
                course = all_courses[course_id]
            else:
                course = Course()
                all_courses[course_id] = course

            course.depends_on.append(prereq_course_id)


            if prereq_course_id in all_courses:
                prereq_course = all_courses[prereq_course_id]
            else:
                prereq_course = Course()
                all_courses[prereq_course_id] = prereq_course

            prereq_course.unblocks.append(course_id)

        studied = set()
        courses_to_check_queue = []
        # initialize courses_to_check_queue
        for course_id, course in all_courses.items():
            if len(course.depends_on) == 0:
                studied.add(course_id)
                courses_to_check_queue.extend(course.unblocks)

        # print(studied)
        # print(courses_to_check_queue)
        while len(courses_to_check_queue) > 0:
            course_id = courses_to_check_queue.pop(0)

            # unsure if really need this. probably not?
            if course_id in studied:
                continue

            course = all_courses[course_id]
            if all(c in studied for c in course.depends_on):
                studied.add(course_id)
                courses_to_check_queue.extend(course.unblocks)

        return len(all_courses) == len(studied)


print(Solution().canFinish(2, [[1, 0]]))
print(Solution().canFinish(2, [[1, 0], [0, 1]]))
