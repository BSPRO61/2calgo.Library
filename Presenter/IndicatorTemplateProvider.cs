﻿namespace _2calgo.Presenter
{
    static class IndicatorTemplateProvider
    {
        private const string FolderPath = @"pack://application:,,,/2calgo.Presenter;component/Templates/Indicator/";

        public static string GetTemplate()
        {
            var mainTemplate = StringResourceReader.Read(FolderPath + "MainTemplate.c");

            return mainTemplate
                .Replace("#InnerParts_PLACE_HOLDER#", InnerPartsProvider.Get())
                .Replace("#OuterParts_PLACE_HOLDER#", OuterPartsProvider.Get());
        }
    }
}
