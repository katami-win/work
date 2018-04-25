/*!
 * @file Task.h
 * @brief Task class
 * @date $Date: 2014-06-17 10:10:29 +0900 (Tue, 17 Jun 2014) $
 *
 *
 * $Id: Task.h 180 2014-06-17 01:10:29Z pi $
 *
 */

#ifndef WEI_TASK_H
#define WEI_TASK_H

#include <pthread.h>

namespace WEIApp
{
  /*!
   * @class Task
   * @brief Task class
   */
  class Task
  {
  public:
    /*!
     *
     * @brief Constructor
     *
     */
    Task();

    /*!
     * @brief Destructor
     *
     */
    virtual ~Task();

    /*!
     *
     * @brief Task open
     * @param args Arguments
     *
     */
    virtual int open(void* args = 0);

    /*!
     *
     * @brief Task close
     * @param flags Flags
     */
    virtual int close(unsigned long flags = 0);

    /*!
     * @brief Execute thread
     */
    virtual int svc();

    /*!
     * @brief Create a thread
     */
    virtual void activate();

    /*!
     * @brief Waiting for the thread terminate
     */
    virtual int wait(void);

    /*!
     * @brief Suspending the task
     */
    virtual int suspend(void);

    /*!
     * @brief Resuming the suspended task
     */
    virtual int resume(void);

    /*!
     * @brief Reset of task count
     */
    virtual void reset();

    /*!
     * @brief Finalizing the task
     */
    virtual void finalize();

    /*!
     * @brief Start thread Execution
     * @param args Thread arguments
     *
     */
    static void* svc_run(void* args = 0);

  private:
    int m_count;
    pthread_t m_thread;
    pthread_attr_t m_attr;
    void* m_args;

  };
};

#endif // WEI_TASK_H
