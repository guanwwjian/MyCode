	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
namespace ¹Ø¼ü102342ID3Ëã·¨ {
	public ref class PropValue
	{
		int n,cno;
		array<array<String^>^> ^pv;
		Hashtable ^ht;

	public: PropValue(String ^filename)
		{
			n=0;
			StreamReader ^sr= gcnew StreamReader(filename);
			cno=Int32::Parse(sr->ReadLine());
			while (sr->ReadLine()) n++;
			pv=gcnew array<array<String^>^>(n);
			ht=gcnew Hashtable();
			sr= gcnew StreamReader(filename);
			String ^line;
			int p=0;
			cno=Int32::Parse(sr->ReadLine());
			while (line=sr->ReadLine())
			{
				pv[p]=line->Split(' ');
				ht->Add(pv[p][0],p);
				p++;
			}
			sr->Close();
		}
		int getcno()
		{
			return cno;
		}
		int count()
		{
			return n;
		}
		int countofp(String ^s)
		{
			return pv[pton(s)]->Length;
		}
		int countofcla()
		{
			return countofp(cno);
		}
		int countofp(int x)
		{
			return pv[x]->Length;
		}
		int pton(String^ s)
		{
			if (ht->Contains(s)) return (int)ht[s];
			else return -1;
		}
		int nij(String^ ii,String ^jj)
		{
			int tt=pton(ii);
			int i;
			for (i=0;i<=pv[tt]->Length-1;i++)
			{
				if (String::Equals(pv[tt][i],jj)) break;
			}
			if (i<=pv[tt]->Length-1)
			{
				return i;
			}
			else
			{
				return -1;
			}
		}
		String^ ntop(int x)
		{
			return gcnew String(pv[x][0]);
		}
		String^ pij(int ii,int jj)
		{
			return gcnew String(pv[ii][jj]);
		}

	};
}