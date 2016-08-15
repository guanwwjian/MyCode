#include"PropValue.h"	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	namespace ¹Ø¼ü102342ID3Ëã·¨ {
		public ref class Samples
		{
		public:int n;
		public:array<array<int>^> ^data;
		public:Samples(String ^filename,PropValue ^rule)
			   {
					n=0;
					int i,j,k;
					StreamReader ^sr= gcnew StreamReader(filename);
					while (sr->ReadLine()) n++;
					array<String^> ^tt;
					data=gcnew array<array<int>^>(n);
					sr= gcnew StreamReader(filename);
					String ^line;
					int p=0;
					while (line=sr->ReadLine())
					{
						tt=line->Split(' ');
						data[p]=gcnew array<int>(tt->Length);
						for (i=0;i<=tt->Length-1;i++)
						{
							data[p][i]=rule->nij(rule->ntop(i),tt[i]);
						}
						p++;
					}
					sr->Close();
			   }
		public:Samples(Samples ^sam,int prop,int value)
			   {
				    n=0;

					for (int i=0;i<=sam->data->Length-1;i++)
						if (sam->data[i][prop]==value)
						{
							n++;
						}
					data=gcnew array<array<int>^>(n);
					int p=0;
					for (int i=0;i<=sam->data->Length-1;i++)
					if (sam->data[i][prop]==value)
					{
						data[p]=gcnew array<int>(sam->data[i]->Length);
						for (int j=0;j<=sam->data[i]->Length-1;j++)
						{
							data[p][j]=sam->data[i][j];
						}
						p++;
					}
			   }
		public:int count()
				{
					return n;
				}
		};
	
	}