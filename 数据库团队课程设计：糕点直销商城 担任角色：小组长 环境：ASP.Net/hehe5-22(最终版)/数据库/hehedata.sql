USE [hehedata]
GO
/****** Object:  Table [dbo].[news]    Script Date: 12/16/2012 23:40:24 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[news](
	[nid] [int] IDENTITY(10000,1) NOT NULL,
	[ntitle] [nchar](256) NOT NULL,
	[details] [text] NULL,
	[enable] [bit] NOT NULL,
 CONSTRAINT [PK_news] PRIMARY KEY CLUSTERED 
(
	[nid] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[image]    Script Date: 12/16/2012 23:40:24 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[image](
	[iid] [int] NOT NULL,
	[Image] [nchar](255) NULL,
 CONSTRAINT [PK_image] PRIMARY KEY CLUSTERED 
(
	[iid] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[advertisement]    Script Date: 12/16/2012 23:40:24 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[advertisement](
	[advid] [int] IDENTITY(10000,1) NOT NULL,
	[advurl] [nchar](256) NOT NULL,
	[width] [int] NULL,
	[height] [int] NULL,
	[x] [int] NULL,
	[y] [int] NULL,
	[enable] [bit] NOT NULL,
	[advname] [nchar](255) NOT NULL,
 CONSTRAINT [PK_advertisement] PRIMARY KEY CLUSTERED 
(
	[advid] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[admin]    Script Date: 12/16/2012 23:40:24 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[admin](
	[aid] [int] IDENTITY(10000,1) NOT NULL,
	[aname] [nchar](20) NOT NULL,
	[password] [nchar](20) NOT NULL,
	[alevel] [int] NOT NULL,
	[enable] [bit] NOT NULL,
 CONSTRAINT [PK_admin] PRIMARY KEY CLUSTERED 
(
	[aid] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[users]    Script Date: 12/16/2012 23:40:24 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[users](
	[uid] [int] IDENTITY(10000,1) NOT NULL,
	[uname] [nchar](20) NOT NULL,
	[password] [nchar](20) NOT NULL,
	[safecode] [nchar](20) NULL,
	[money] [int] NULL,
	[lastip] [nchar](15) NULL,
	[enable] [bit] NOT NULL,
	[ban] [bit] NOT NULL,
 CONSTRAINT [PK_user] PRIMARY KEY CLUSTERED 
(
	[uid] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[type]    Script Date: 12/16/2012 23:40:24 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[type](
	[tid] [int] IDENTITY(10000,1) NOT NULL,
	[tname] [nchar](40) NOT NULL,
	[enable] [bit] NOT NULL,
 CONSTRAINT [PK_type] PRIMARY KEY CLUSTERED 
(
	[tid] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[recharge]    Script Date: 12/16/2012 23:40:24 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[recharge](
	[rid] [int] IDENTITY(10000,1) NOT NULL,
	[rcode] [nchar](40) NOT NULL,
	[password] [nchar](10) NOT NULL,
	[money] [int] NOT NULL,
	[enable] [bit] NOT NULL,
 CONSTRAINT [PK_recharge] PRIMARY KEY CLUSTERED 
(
	[rid] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[product]    Script Date: 12/16/2012 23:40:24 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[product](
	[pid] [int] IDENTITY(10000,1) NOT NULL,
	[pname] [nchar](100) NOT NULL,
	[tid] [int] NULL,
	[introduce] [nchar](255) NULL,
	[picurl] [nchar](255) NULL,
	[stock] [int] NOT NULL,
	[price] [int] NOT NULL,
	[bought] [int] NOT NULL,
	[enable] [bit] NULL,
 CONSTRAINT [PK_product] PRIMARY KEY CLUSTERED 
(
	[pid] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[orders]    Script Date: 12/16/2012 23:40:24 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[orders](
	[oid] [int] IDENTITY(10000,1) NOT NULL,
	[pid] [int] NOT NULL,
	[uid] [int] NOT NULL,
	[date] [date] NULL,
	[count] [int] NOT NULL,
	[status] [int] NOT NULL,
	[grade] [int] NULL,
	[evalution] [nchar](256) NULL,
	[enable] [bit] NOT NULL,
	[zipcode] [nchar](10) NULL,
	[useraddress] [text] NULL,
	[realname] [nchar](10) NULL,
	[phonenumber] [nchar](15) NULL,
	[additionalmessage] [text] NULL,
 CONSTRAINT [PK_order] PRIMARY KEY CLUSTERED 
(
	[oid] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Default [DF_admin_alevel]    Script Date: 12/16/2012 23:40:24 ******/
ALTER TABLE [dbo].[admin] ADD  CONSTRAINT [DF_admin_alevel]  DEFAULT ((0)) FOR [alevel]
GO
/****** Object:  Default [DF_admin_enable]    Script Date: 12/16/2012 23:40:24 ******/
ALTER TABLE [dbo].[admin] ADD  CONSTRAINT [DF_admin_enable]  DEFAULT ((1)) FOR [enable]
GO
/****** Object:  Default [DF_advertisement_enable]    Script Date: 12/16/2012 23:40:24 ******/
ALTER TABLE [dbo].[advertisement] ADD  CONSTRAINT [DF_advertisement_enable]  DEFAULT ((1)) FOR [enable]
GO
/****** Object:  Default [DF_news_enable]    Script Date: 12/16/2012 23:40:24 ******/
ALTER TABLE [dbo].[news] ADD  CONSTRAINT [DF_news_enable]  DEFAULT ((1)) FOR [enable]
GO
/****** Object:  Default [DF_order_count]    Script Date: 12/16/2012 23:40:24 ******/
ALTER TABLE [dbo].[orders] ADD  CONSTRAINT [DF_order_count]  DEFAULT ((1)) FOR [count]
GO
/****** Object:  Default [DF_order_status]    Script Date: 12/16/2012 23:40:24 ******/
ALTER TABLE [dbo].[orders] ADD  CONSTRAINT [DF_order_status]  DEFAULT ((0)) FOR [status]
GO
/****** Object:  Default [DF_order_enable]    Script Date: 12/16/2012 23:40:24 ******/
ALTER TABLE [dbo].[orders] ADD  CONSTRAINT [DF_order_enable]  DEFAULT ((1)) FOR [enable]
GO
/****** Object:  Default [DF_product_stock]    Script Date: 12/16/2012 23:40:24 ******/
ALTER TABLE [dbo].[product] ADD  CONSTRAINT [DF_product_stock]  DEFAULT ((0)) FOR [stock]
GO
/****** Object:  Default [DF_recharge_money]    Script Date: 12/16/2012 23:40:24 ******/
ALTER TABLE [dbo].[recharge] ADD  CONSTRAINT [DF_recharge_money]  DEFAULT ((0)) FOR [money]
GO
/****** Object:  Default [DF_recharge_enable]    Script Date: 12/16/2012 23:40:24 ******/
ALTER TABLE [dbo].[recharge] ADD  CONSTRAINT [DF_recharge_enable]  DEFAULT ((1)) FOR [enable]
GO
/****** Object:  Default [DF_type_enable]    Script Date: 12/16/2012 23:40:24 ******/
ALTER TABLE [dbo].[type] ADD  CONSTRAINT [DF_type_enable]  DEFAULT ((1)) FOR [enable]
GO
/****** Object:  Default [DF_users_money]    Script Date: 12/16/2012 23:40:24 ******/
ALTER TABLE [dbo].[users] ADD  CONSTRAINT [DF_users_money]  DEFAULT ((0)) FOR [money]
GO
/****** Object:  Default [DF_users_enable]    Script Date: 12/16/2012 23:40:24 ******/
ALTER TABLE [dbo].[users] ADD  CONSTRAINT [DF_users_enable]  DEFAULT ((1)) FOR [enable]
GO
/****** Object:  Default [DF_users_ban]    Script Date: 12/16/2012 23:40:24 ******/
ALTER TABLE [dbo].[users] ADD  CONSTRAINT [DF_users_ban]  DEFAULT ((0)) FOR [ban]
GO
/****** Object:  ForeignKey [FK_order_product]    Script Date: 12/16/2012 23:40:24 ******/
ALTER TABLE [dbo].[orders]  WITH CHECK ADD  CONSTRAINT [FK_order_product] FOREIGN KEY([pid])
REFERENCES [dbo].[product] ([pid])
GO
ALTER TABLE [dbo].[orders] CHECK CONSTRAINT [FK_order_product]
GO
/****** Object:  ForeignKey [FK_order_users]    Script Date: 12/16/2012 23:40:24 ******/
ALTER TABLE [dbo].[orders]  WITH CHECK ADD  CONSTRAINT [FK_order_users] FOREIGN KEY([uid])
REFERENCES [dbo].[users] ([uid])
GO
ALTER TABLE [dbo].[orders] CHECK CONSTRAINT [FK_order_users]
GO
/****** Object:  ForeignKey [FK_product_type]    Script Date: 12/16/2012 23:40:24 ******/
ALTER TABLE [dbo].[product]  WITH CHECK ADD  CONSTRAINT [FK_product_type] FOREIGN KEY([tid])
REFERENCES [dbo].[type] ([tid])
GO
ALTER TABLE [dbo].[product] CHECK CONSTRAINT [FK_product_type]
GO
