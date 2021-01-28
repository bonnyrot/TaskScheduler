Using std::chrono::time_literals;

Scheduler::instance().add([](){ std::cout << “Hello” << std::endl;}, 100ms);
Scheduler::instance().add([this](){ checkConfig(); }, 1s);
std::mutex(m);
std::vector<std::thread> pool;

Class Scheduler : public Singleton<Scheduler>
{

Public: 
	~Scheduler(){ should_stop = true; poller.join();}
	Void add (std::function<void()>&& func, const std::chrono::system_time::time_period& period);
Private:
std::map<std::chrono::system_time::time_point,std::function<void()>> tasks;
};


scheduler::add(std::function<void()>&& func, const std::chrono::system_time::time_period& period){
	std::uniqueue_lock<mutex> lock(m) 
	tasks.insert(func);
cond.notify(lock);
}


	
scheduler::run(){
Poller = std::thread([](){
while(!should_stop){
If (std::uniqueue_lock<mutex> lock(m); tasks.begin().first >= std::chrono::system_time::now())
{
	Auto task = *tasks.begin();
	tasks.erase(tasks.begin());
	pool.submit([task](){
		task.func();
		Scheduler::instance().add(task.func, std::chrono::system_time::now() + task.period);

});
}
Else
{
	Auto sleep = task.period-std::chrono::system_time::now();
	cond.wait_for(lock,[]{!tasks.empty()}, sleep);

}
}




