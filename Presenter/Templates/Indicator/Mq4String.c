class Mq4String
{
	private readonly string _value;
	
	public Mq4String(string value)
	{
		_value = value;
	}
	
	public static implicit operator Mq4String(string value)
	{
		return new Mq4String(value);
	}
	
	public static implicit operator Mq4String(int value)
	{
		return new Mq4String(value.ToString());
	}
		
	public static implicit operator Mq4String(Mq4Null mq4Null)
	{
		return new Mq4String(null);
	}
	
	public static implicit operator string(Mq4String mq4String)
	{
		return mq4String._value;
	}
	
	public override string ToString()
	{
		return _value.ToString();
	}
}