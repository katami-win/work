// -*- C++ -*-
/*!
 * @file Task.cpp
 * @brief Task class
 * @date $Date: 2014-06-17 10:10:29 +0900 (Tue, 17 Jun 2014) $
 *
 *
 * $Id: Task.cpp 180 2014-06-17 01:10:29Z pi $
 *
 */

#include <Task.h>

namespace WEIApp
{

  /*!
   * @brief Constructor
   */
  Task::Task()
    : m_count(0)
  {
    ::pthread_attr_init(&m_attr);
  }

  /*!
   * @brief Destructor
   */
  Task::~Task()
  {
    m_count = 0;
  }

  /*!
   * @brief Task open
   */
  int Task::open(void* args)
  {
    return 0;
  }

  /*!
   * @brief Task close
   */
  int Task::close(unsigned long flags)
  {
    return 0;
  }

  /*!
   * @brief Execute thread
   */
  int Task::svc()
  {
    return 0;
  }

  /*!
   * @brief Create a thread
   */
  void Task::activate()
  {
    if (m_count == 0)
      {
        ::pthread_create(&m_thread,
                         &m_attr,
                         (void* (*)(void*))Task::svc_run,
                         this);
        ++m_count;
      };
  }

  /*!
   * @brief Waiting for the thread terminate
   */
  int Task::wait(void)
  {
    if (m_count > 0)
      {
        void* retval;
        ::pthread_join(m_thread, &retval);
      }
    return 0;
  }

  /*!
   * @brief Suspending the task
   */
  int Task::suspend(void)
  {
    return 0;
  }

  /*!
   * @brief Resuming the suspended task
   */
  int Task::resume(void)
  {
    return 0;
  }

  /*!
   * @brief Reset of task count
   */
  void Task::reset()
  {
    m_count = 0;
  }

  /*!
   * @brief Finalizing the task
   */
  void Task::finalize()
  {
    reset();
  }

  /*!
   * @brief Start thread Execution
   */
  void* Task::svc_run(void* args)
  {
    Task* t = (WEIApp::Task*)args;
    int status;
    status = t->svc();
    t->finalize();
    return 0;
  }
};


