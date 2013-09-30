#References_PLACE_HOLDER##Usings_PLACE_HOLDER#

namespace cAlgo.Robots
{
    [Robot()]
    public class #AlgoName_PLACE_HOLDER# : Robot
    {
#Mq4Functions_PLACE_HOLDER#

[Conditional("SendMail")]
//{
		[Parameter("Email from", DefaultValue = "your_email@gmail.com")]
        public string EmailAddressFrom { get; set; }

        [Parameter("Email to", DefaultValue = "your_email@gmail.com")]
        public string EmailAddressTo { get; set; }
//}

#Parameters_PLACE_HOLDER#

#Mq4Fields_PLACE_HOLDER#
        
	protected override void OnStart()
    {
		CommonInitialize();			            
		#DebugActions_PLACE_HOLDER#           

		Mq4Init();

		var mq4Thread = new Thread(Mq4ThreadStart);
		mq4Thread.Start();
    }

    AutoResetEvent _mq4Start = new AutoResetEvent(false);
    AutoResetEvent _mq4Finished = new AutoResetEvent(false);

    protected override void OnTick()
    {
    	_mq4Start.Set();
    	_mq4Finished.WaitOne();		
    }

    private void Mq4ThreadStart()
    {
    	while (_mq4Start.WaitOne())
    	{
			try
			{
				Mq4Start();
			}
			catch(Exception e)
			{
				#HandleException_PLACE_HOLDER#
				throw;
			}
    		_mq4Finished.Set();
    	}
    }

	private IndicatorDataSeries CreateDataSeries()
	{
		return null;
	}

#InnerParts_PLACE_HOLDER#
	}

	//Custom Indicators Place Holder

#OuterParts_PLACE_HOLDER#

}